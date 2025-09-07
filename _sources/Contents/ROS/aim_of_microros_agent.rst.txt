🎯 Mục đích của micro-ROS Agent

Trong hệ sinh thái micro-ROS, có 2 phần:

Client (thiết bị nhúng, MCU, board STM32/ESP32, …)
→ chạy firmware micro-ROS, publish/subscribe topic, gửi service, action…

Agent (chạy trên PC/Raspberry Pi/Linux host)
→ cầu nối giữa thiết bị nhúng và ROS 2 middleware (DDS).

🔗 Cách hoạt động

Client (MCU) không thể tự nói chuyện trực tiếp với DDS/ROS 2 core.

Client gửi dữ liệu qua transport (UART/Serial, UDP, TCP, CAN, …).

Agent nhận dữ liệu này, dịch sang message DDS chuẩn → đưa vào ROS 2 graph.

Ngược lại, Agent cũng nhận topic/service từ ROS 2 rồi chuyển xuống Client.

👉 Nói nôm na:
Agent = “bridge” giúp board nhỏ (STM32/ESP32, …) xuất hiện trong ROS 2 như 1 node bình thường.

📌 Ví dụ

ESP32 chạy micro-ROS firmware, publish topic /imu/data.

ESP32 chỉ biết gửi UART.

micro-ROS Agent trên PC nhận UART → dịch thành topic ROS 2 → giờ bạn có thể:

ros2 topic echo /imu/data


thấy dữ liệu từ ESP32 như từ 1 node ROS 2.

Ngược lại:

PC gửi lệnh /cmd_vel (geometry_msgs/Twist).

Agent chuyển qua UART → ESP32 nhận và điều khiển robot.

✅ Tóm gọn

Client = node chạy trên vi điều khiển.

Agent = cầu nối để client “hiện diện” trong ROS 2.

Nếu không có Agent → vi điều khiển không “thấy” và không “được thấy” trong hệ ROS 2.