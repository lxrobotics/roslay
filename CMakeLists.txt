cmake_minimum_required(VERSION 2.8.3)
project(roslay)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rosserial_arduino
  rosserial_client
  std_msgs
)

################################################
## Declare ROS messages, services and actions ##
################################################

add_message_files(
  FILES
  Relay.msg
)

generate_messages(
)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES roslay
  CATKIN_DEPENDS message_runtime roscpp rosserial_arduino rosserial_client std_msgs
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

add_executable(roslaytest
  src/roslaytest.cpp
)

target_link_libraries(roslaytest
  ${catkin_LIBRARIES}
)


#############
## Install ##
#############

#############
## Testing ##
#############

