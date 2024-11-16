I2C BITBANGING
=======================

.. contents:: 
    :depth: 2

Bit-bangging
-------------------

* Bit-bangging là một kỹ thuật thực hiện các chuẩn giao tiếp (I2C, SPI, UART …) bằng các 
chân GPIO thông thường. Hay nói cách khác, bằng cách define phù hợp thứ tự các mức logic LOW hay HIGH 
của GPIO ta có thể giao tiếp theo các chuẩn như I2C, SPI, UART…Như vậy, khi 
phần cứng không hỗ trợ, ta vẫn có thể giao tiếp bình thường bằng phần mềm, 
chẳng hạn 8051 có thể giao tiếp I2C. Đây rõ ràng là một lợi thế rất lớn.Tuy nhiên, 
kỹ thuật này cũng gặp phải nhiều bất lợi. Thông thường đối với module phần cứng. 
Mỗi thao tác chỉ thực hiện trong vòng 1 chu kỳ (chẳng hạn như việc send tín hiệu Start I2C). 
Trong khi đó, khi dùng Bit-Banging thì phải mất nhiều hơn 1 chu kỳ do cần lần lượt config các 
chân GPIO (sẽ làm rõ ở phần tiếp theo). Ngoài ra, Bit-Banging còn khiến cho CPU tốn nhiều 
thời gian để tính toán hơn và như vậy sẽ kém hiệu quả khi cần giao tiếp ở tốc độ cao hay 
với những dữ liệu lớn.

* Căn cứ theo chuẩn I2C, các đường SDA và SCL trên các thiết bị có cấu hình “cực góp mở” 
(open-drain hoặc open-collector, tham khảo các mạch số dùng transistor để hiểu thêm), 
nghĩa là cần có các “điện trở kéo lên” (pull-up resistor) cho các đường này. Ở trạng 
thái nghỉ (Idle), 2 chân SDA và SCL ở mức cao


* Master: là chip khởi động quá trình truyền nhận, phát đi địa chỉ của thiết bị cần giao tiếp 
và tạo xung giữ nhịp trên đường SCL.

* Slave: là chip có một địa chỉ cố định, được gọi bởi Master và phục vụ yêu cầu từ Master.

* SDA- Serial Data: là đường dữ liệu nối tiếp, tất cả các thông tin về địa chỉ hay dữ liệu đều 
được truyền trên đường này theo thứ tự từng bit một. Chú ý là trong chuẩn I2C, bit có trọng 
số lớn nhất (MS  được truyền trước nhất, đặc điểm này ngược lại với chuẩn UART).
SCL-Serial Clock: là đường giữ nhịp nối tiếp. TWI (I2C) là chuần truyền thông nối tiếp đồng 
bộ, cần có 1 đường tạo xung giữ nhịp cho quá trình truyền/nhận, cứ mỗi xung trên đường giữ nhịp 
SCL, một bit dữ liệu trên đường SDA sẽ được lấy mẫu (sample). Dữ liệu nối tiếp trên đường SDA 
được lấy mẫu khi đường SCL ở mức cao trong một chu kỳ giữ nhịp, vì thế đường SDA không được đổi 
trạng thái khi SCL ở mức cao (trừ START và STOP condition). Chân SDA có thể được đổi trạng thái 
khi SCL ở mức thấp.