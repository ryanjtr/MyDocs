#include <Arduino.h>
#include <SPI.h>
#include <TMC51X0.hpp>

// SPI0 của Pico/Pico 2
constexpr uint8_t PIN_SCK  = 18;
constexpr uint8_t PIN_MOSI = 19;
constexpr uint8_t PIN_MISO = 16;

// 3 chân CS cho 3 driver (ĐỔI CHO KHỚP DÂY CỦA BẠN)
constexpr uint8_t CS_PINS[3] = { 17, 14, 15 };

// Đơn vị thực = radian: ~8149 µstep / rad (200 step/rev * 256 µstep / 2π)
const tmc51x0::ConverterParameters converter_params = {
  .microsteps_per_real_position_unit = 8149
};

// Dòng, stealth, v.v. dùng chung (có thể sửa riêng từng motor nếu muốn)
const tmc51x0::DriverParameters driver_params_real = {
  .run_current = 50,
  .hold_current = 10,
  .pwm_offset = 30,
  .pwm_gradient = 10,
  .stealth_chop_threshold = 100,  // chỉ ảnh hưởng chế độ stealth/spread, không phải tốc độ
};

// Giới hạn vận tốc/gia tốc (Position mode)
const tmc51x0::ControllerParameters ctrl_params_real = {
  .ramp_mode = tmc51x0::PositionMode,
  .max_velocity = 20,     // rad/s
  .max_acceleration = 2,  // rad/s^2
};

// (Tuỳ chọn) Tham số homing nếu bạn vẫn muốn chạy homing trước
const tmc51x0::HomeParameters home_params_real = {
  .run_current = 25,
  .hold_current = 10,
  .target_position = -100,
  .velocity = 20,
  .acceleration = 2,
};
const tmc51x0::StallParameters stall_params_real = {
  .stall_guard_threshold = 3,
  .cool_step_threshold = 10
};

// Mỗi vòng lặp sẽ di chuyển TƯƠNG ĐỐI bấy nhiêu (đơn vị rad)
const float MOVE_DELTA = -10.0f;

const uint32_t SERIAL_BAUD = 115200;
const uint16_t LOG_DELAY_MS = 200;

// 3 đối tượng driver
TMC51X0 motor[3];

// Mỗi motor cần giữ bản "đơn vị chip" riêng
tmc51x0::ControllerParameters ctrl_params_chip[3];
tmc51x0::HomeParameters       home_params_chip[3];
tmc51x0::StallParameters      stall_params_chip[3];

void init_one_motor(int i, uint8_t cs_pin) {
  // SPI params cho motor i (chung SPI, khác CS)
  const tmc51x0::SpiParameters spi_params_i = { .spi_ptr = &SPI, .chip_select_pin = cs_pin };

  motor[i].setupSpi(spi_params_i);
  motor[i].converter.setup(converter_params);

  // Đổi tham số "real" -> "chip" rồi ghi
  auto driver_params_chip = motor[i].converter.driverParametersRealToChip(driver_params_real);
  ctrl_params_chip[i]     = motor[i].converter.controllerParametersRealToChip(ctrl_params_real);
  home_params_chip[i]     = motor[i].converter.homeParametersRealToChip(home_params_real);
  stall_params_chip[i]    = motor[i].converter.stallParametersRealToChip(stall_params_real);

  motor[i].driver.setup(driver_params_chip);
  motor[i].controller.setup(ctrl_params_chip[i]);

  // Kiểm tra giao tiếp SPI
  uint8_t retry = 15;
  while (!motor[i].communicating() && retry--) {
    delay(50);
  }

  // Bật driver (lưu ý ENN phần cứng phải LOW ở module)
  motor[i].driver.enable();

  // Về vận tốc 0 cho sạch sẽ
  motor[i].controller.beginRampToZeroVelocity();
  while (!motor[i].controller.zeroVelocity()) { delay(5); }
  motor[i].controller.endRampToZeroVelocity();
}

void move_relative_rad(int i, float delta_rad) {
  // Đọc vị trí hiện tại (đơn vị chip)
  int32_t cur_chip = motor[i].controller.readActualPosition();

  // Quy đổi delta rad -> chip units
  int32_t delta_chip = motor[i].converter.positionRealToChip(delta_rad);

  // Viết mục tiêu = hiện tại + delta (dịch TƯƠNG ĐỐI)
  motor[i].controller.writeTargetPosition(cur_chip + delta_chip);
}

bool all_reached() {
  for (int i = 0; i < 3; ++i)
    if (!motor[i].controller.positionReached()) return false;
  return true;
}

void print_positions_rad() {
  for (int i = 0; i < 3; ++i) {
    int32_t x_chip = motor[i].controller.readActualPosition();
    int32_t x_rad  = motor[i].converter.positionChipToReal(x_chip);
    Serial.print("M"); Serial.print(i); Serial.print(": ");
    Serial.print(x_rad); Serial.print(" rad   ");
  }
  Serial.println();
}

void setup() {
  Serial.begin(SERIAL_BAUD);

  // SPI pinout & begin
  SPI.setSCK(PIN_SCK);
  SPI.setTX(PIN_MOSI);
  SPI.setRX(PIN_MISO);
  SPI.begin();
  // (Tuỳ chọn test) ép Mode3 và tốc độ vừa phải: SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));

  // Khởi tạo 3 motor
  for (int i = 0; i < 3; ++i) {
    init_one_motor(i, CS_PINS[i]);
  }

  Serial.println("Init done.");
}

void loop() {
  // Ví dụ: mỗi vòng lặp, di chuyển CẢ 3 motor thêm MOVE_DELTA (tương đối)
  Serial.print("Move relative (rad): "); Serial.println(MOVE_DELTA);
  for (int i = 0; i < 3; ++i) move_relative_rad(i, MOVE_DELTA);

  // Theo dõi tới khi cả 3 tới đích
  while (!all_reached()) {
    print_positions_rad();
    delay(LOG_DELAY_MS);
  }
  Serial.println("All motors reached target.\n");

  delay(1000);

  // Bạn có thể đảo chiều lần sau, hoặc đọc lệnh từ Serial để set delta mới…
  // Ví dụ đảo chiều để qua lại:
  // MOVE_DELTA = -MOVE_DELTA;  // nếu bạn đổi sang biến không-const
}
