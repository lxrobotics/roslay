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
  ros::init(argc, argv, "ardumotetest");
  
  ros::NodeHandle node_handle;

  /* Create the two service clients for the two services */


  
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

