/**
 * \author Alexander Entinger, MSc
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <Arduino.h>

#include <ros.h>
#include <std_msgs/Bool.h>

#include "RelayShield.h"

/**************************************************************************************
 * PROTOTYPES
 **************************************************************************************/

void setRelay1Callback(const std_msgs::Bool& relay_1_msg);
void setRelay2Callback(const std_msgs::Bool& relay_2_msg);
void setRelay3Callback(const std_msgs::Bool& relay_3_msg);
void setRelay4Callback(const std_msgs::Bool& relay_4_msg);
void commonRelayCallback(ERelaySelect const sel, const std_msgs::Bool& relay_msg);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ros::NodeHandle node_handle;

ros::Subscriber<std_msgs::Bool> relay_1_subscriber("/relay1", &setRelay1Callback);
ros::Subscriber<std_msgs::Bool> relay_2_subscriber("/relay2", &setRelay2Callback);
ros::Subscriber<std_msgs::Bool> relay_3_subscriber("/relay3", &setRelay3Callback);
ros::Subscriber<std_msgs::Bool> relay_4_subscriber("/relay4", &setRelay4Callback);

/**************************************************************************************
 * ARDUINO FRAMEWORK FUNCTIONS
 **************************************************************************************/

void setup() 
{
  RelayShield::begin();

  node_handle.getHardware()->setBaud(115200);
  node_handle.initNode();

  node_handle.subscribe(relay_1_subscriber);
  node_handle.subscribe(relay_2_subscriber);
  node_handle.subscribe(relay_3_subscriber);
  node_handle.subscribe(relay_4_subscriber);
}

void loop() 
{
  node_handle.spinOnce();
}

/**************************************************************************************
 * OUR FUNCTIONS
 **************************************************************************************/

void setRelay1Callback(const std_msgs::Bool& relay_1_msg)
{
  commonRelayCallback(REL1, relay_1_msg);
}

void setRelay2Callback(const std_msgs::Bool& relay_2_msg)
{
  commonRelayCallback(REL2, relay_2_msg);
}

void setRelay3Callback(const std_msgs::Bool& relay_3_msg)
{
  commonRelayCallback(REL3, relay_3_msg);
}

void setRelay4Callback(const std_msgs::Bool& relay_4_msg)
{
  commonRelayCallback(REL4, relay_4_msg);
}

void commonRelayCallback(ERelaySelect const sel, const std_msgs::Bool& relay_msg)
{
  bool const turn_on_relay = (relay_msg.data == true);

  if(turn_on_relay) RelayShield::turnOn (sel);
  else              RelayShield::turnOff(sel);
}
