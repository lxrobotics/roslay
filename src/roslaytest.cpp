/* Copyright (c) 2016, Alexander Entinger / LXRobotics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of motor-controller-highpower-motorshield nor the names of its
 *  contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

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

