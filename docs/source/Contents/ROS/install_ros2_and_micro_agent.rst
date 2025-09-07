✅ Quy trình chuẩn cài ROS 2 Humble + micro-ROS Agent (Ubuntu 22.04 Jammy)
1. Xóa sạch gói ROS bị lỗi (nếu có)
sudo apt remove --purge "ros-*"
sudo apt remove --purge python3-ros* python3-colcon* python3-catkin* python3-rospkg* python3-rosdistro* python3-bloom* -y
sudo apt autoremove -y
sudo apt clean

2. Thêm repo ROS 2 chính thức
sudo apt update && sudo apt install -y locales curl gnupg lsb-release software-properties-common
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8

sudo add-apt-repository universe -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
  | sudo tee /usr/share/keyrings/ros-archive-keyring.gpg >/dev/null

echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] \
http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" \
| sudo tee /etc/apt/sources.list.d/ros2.list >/dev/null

3. Cài ROS 2 Humble desktop
sudo apt update
sudo apt upgrade -y
sudo apt install ros-humble-desktop python3-colcon-common-extensions python3-rosdep python3-rospkg python3-rosdistro python3-catkin-pkg -y

4. Khởi tạo rosdep
sudo rosdep init || true
rosdep update

5. Nạp môi trường ROS

Thêm vào ~/.bashrc:

echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
source ~/.bashrc

**Kiểm tra ROS 2**

ros2 run demo_nodes_cpp talker
# mở terminal khác
ros2 run demo_nodes_cpp listener


6. Tạo workspace cho micro-ROS Agent
mkdir -p ~/uros_agent_ws/src
cd ~/uros_agent_ws
git clone -b humble https://github.com/micro-ROS/micro_ros_setup.git src/micro_ros_setup

rosdep update
rosdep install --from-paths src --ignore-src -y --rosdistro humble

colcon build
source install/local_setup.bash

7. Tạo và build Agent
# Tạo agent workspace
ros2 run micro_ros_setup create_agent_ws.sh

# Build agent
ros2 run micro_ros_setup build_agent.sh

# Nạp lại env
source install/local_setup.bash

8. Chạy Agent

Serial:

ros2 run micro_ros_agent micro_ros_agent serial -v6 --dev /dev/ttyACM0 -b 115200


UDP:

ros2 run micro_ros_agent micro_ros_agent udp4 -v6 -p 8888

⚠️ Nếu lỗi vẫn còn

Chạy:

sudo apt --fix-broken install -y


rồi lặp lại từ bước 3.

👉 Với quy trình này bạn chỉ cần chạy tuần tự, không cần mò thủ công nữa.


6) Chạy Agent (để terminal này mở nguyên):

ros2 run micro_ros_agent micro_ros_agent udp4 -v6 -p 8888


Lưu ý: sau mỗi lần mở terminal mới, bạn cần:

source /opt/ros/humble/setup.bash
source ~/uros_agent_ws/install/local_setup.bash