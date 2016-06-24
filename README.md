# roslay
Control an LXRobotics Relay Shield via ROS.

## Interface

### Subscribed Topics
* **`/relay`** ([roslay/Relay])

Turn the relay 1/2/3/4 on the relay shield on or off.

### Published Topics
*None*

### Services
*None*

### Parameters
* **`port`** / std::string / Default: **/dev/ttyACM0**

The device node under which the Arduino registers itself with the Arduino Uno.

* **`baud`** / int / Default: **115200**

The baud rate which is used for the communication between the PC and the Arduino Uno.

## Installation

### Dependencies
```
sudo apt-get install arduino ros-indigo-rosserial ros-indigo-rosserial-arduino
```

### Building
```
cd ~/catkin_ws/src
git clone https://github.com/lxrobotics/roslay.git
cd ..
catkin_make
```

### Download
* Set the port under which the Arduino is connected to the PC by modifying [firmware/CMakeLists]
```
PORT /dev/ttyUSB0
```
* Download to the Arduino
```
catkin_make roslay_firmware_roslay-upload
```

### Start
* Set the port under which the Arduino is connected to the PC by modifying [launch/roslay.launch]
```
<param name="port" value="/dev/ttyUSB0"/> 
```
* Start via roslaunch
```
roslaunch roslay roslay.launch
```

[roslay/Relay]: https://github.com/lxrobotics/roslay/blob/master/msg/Relay.msg
[firmware/CMakeLists]: https://github.com/lxrobotics/roslay/blob/master/firmware/CMakeLists.txt
[launch/roslay.launch]: https://github.com/lxrobotics/roslay/blob/master/launch/roslay.launch
