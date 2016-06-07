/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdlib.h>

#include <iostream>

#include <ros/ros.h>

#include <roslay/Relay.h>

/**************************************************************************************
 * PROTOTYPES
 **************************************************************************************/

void handleSetRelay             (ros::Publisher &relay_publisher);
void handleExit                 ();
void handleInvalidValue         ();

/**************************************************************************************
 * MAIN
 **************************************************************************************/

int main(int argc, char **argv)
{
  ros::init(argc, argv, "roslaytest");
  
  ros::NodeHandle node_handle;

  /* Create the publisher for sending relay messages to the arduino */
  
  ros::Publisher relay_publisher = node_handle.advertise<roslay::Relay>("/relay", 10);

  /* Provide a crude menu for selecting which service one wants to invoke */

  char cmd = 0;

  do
  {
    std::cout << std::endl;
    std::cout << "[s]et relay" << std::endl;
    std::cout << "[q]uit" << std::endl;

    std::cout << ">>"; std::cin >> cmd;

    switch(cmd)
    {
    case 's': handleSetRelay    (relay_publisher);  break;
    case 'q': handleExit        ();                 break;
    default:  handleInvalidValue();                 break;
    }
  } while(cmd != 'q');

  return EXIT_SUCCESS;
}

/**************************************************************************************
 * OUR FUNCTIONS
 **************************************************************************************/

void handleSetRelay(ros::Publisher &relay_publisher)
{
  std::cout << "Enter relay number (0 - 3):";
  size_t relay_number;
  std::cin >> relay_number;
  std::cout << "turn relay o[n]" << std::endl;
  std::cout << "turn relay of[f]" << std::endl;
  char relay_cmd = 0;
  std::cout << ">> "; std::cin >> relay_cmd;
  
  roslay::Relay msg;
  msg.relay = static_cast<uint8_t>(relay_number);
  msg.turn_on = relay_cmd == 'n';

  relay_publisher.publish(msg);
}

void handleExit()
{
  std::cout << "Exiting function roslaytest" << std::endl;
}

void handleInvalidValue()
{
  std::cout << "Invalid input value" << std::endl;
}

