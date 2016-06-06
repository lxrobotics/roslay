# roslay
Control an LXRobotics Relay Shield via ROS.

## Interface

### Subscribed Topics
* **`/relay1`** ([std_msgs/Bool])
* **`/relay2`** ([std_msgs/Bool])
* **`/relay3`** ([std_msgs/Bool])
* **`/relay4`** ([std_msgs/Bool])

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

[std_msgs/Bool]: http://docs.ros.org/api/std_msgs/html/msg/Bool.html

