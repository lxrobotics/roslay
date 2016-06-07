/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdlib.h>

#include <iostream>

#include <ros/ros.h>

#include <std_msgs/Bool.h>

/**************************************************************************************
 * PROTOTYPES
 **************************************************************************************/

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
  
  ros::Publisher relay_publisher = node_handle.advertise<std_msgs::Bool>("/relay", 10);

  /* Provide a crude menu for selecting which service one wants to invoke */

  char cmd = 0;

  do
  {
    std::cout << std::endl;
    std::cout << "[q]uit" << std::endl;

    std::cout << ">>"; std::cin >> cmd;

    switch(cmd)
    {
    case 'q': handleExit                 ();                       break;
    default:  handleInvalidValue         ();                       break;
    }
  } while(cmd != 'q');

  return EXIT_SUCCESS;
}

/**************************************************************************************
 * OUR FUNCTIONS
 **************************************************************************************/

void handleExit()
{
  std::cout << "Exiting function ardumotetest" << std::endl;
}

void handleInvalidValue()
{
  std::cout << "Invalid input value" << std::endl;
}

