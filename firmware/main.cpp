/**
 * \author Alexander Entinger, MSc
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <Arduino.h>

#include <ros.h>
#include <std_msgs/Bool.h>

#include <roslay/Relay.h>

#include "RelayShield.h"

/**************************************************************************************
 * PROTOTYPES
 **************************************************************************************/

void setRelayCallback(const roslay::Relay& relay_msg);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ros::NodeHandle node_handle;

ros::Subscriber<roslay::Relay> relay_subscriber("/relay", &setRelayCallback);

/**************************************************************************************
 * ARDUINO FRAMEWORK FUNCTIONS
 **************************************************************************************/

void setup() 
{
  RelayShield::begin();

  node_handle.getHardware()->setBaud(115200);
  node_handle.initNode();

  node_handle.subscribe(relay_subscriber);
}

void loop() 
{
  node_handle.spinOnce();
}

/**************************************************************************************
 * OUR FUNCTIONS
 **************************************************************************************/


void setRelayCallback(const roslay::Relay& relay_msg)
{
  ERelaySelect const relay = (ERelaySelect)(relay_msg.relay);

  if(relay_msg.turn_on) RelayShield::turnOn (relay);
  else                  RelayShield::turnOff(relay);
}
