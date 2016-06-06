cmake_minimum_required(VERSION 2.8.3)
project(roslay)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rosserial_arduino
  rosserial_client
  std_msgs
)

################################################
## Declare ROS messages, services and actions ##
################################################

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES roslay
  CATKIN_DEPENDS roscpp rosserial_arduino rosserial_client std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

rosserial_generate_ros_lib(
  PACKAGE rosserial_arduino
  SCRIPT make_libraries.py
)

rosserial_configure_client(
  DIRECTORY firmware
  TOOLCHAIN_FILE ${ROSSERIAL_ARDUINO_TOOLCHAIN}
)

rosserial_add_client_target(firmware roslay ALL)
rosserial_add_client_target(firmware roslay-upload)

#############
## Install ##
#############

#############
## Testing ##
#############

