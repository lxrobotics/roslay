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

#include "RelayShield.h"

/**************************************************************************************
 * GLOBAL CONSTANTS
 **************************************************************************************/

static int const RELAY_1_PIN = 2;
static int const RELAY_2_PIN = 3;
static int const RELAY_3_PIN = 8;
static int const RELAY_4_PIN = 9;

/**************************************************************************************
 * PUBLIC FUNCTIONS
 **************************************************************************************/

void RelayShield::begin()
{
  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);
  pinMode(RELAY_3_PIN, OUTPUT);
  pinMode(RELAY_4_PIN, OUTPUT);

  RelayShield::turnOff(REL1);
  RelayShield::turnOff(REL2);
  RelayShield::turnOff(REL3);
  RelayShield::turnOff(REL4);
}

void RelayShield::turnOn(ERelaySelect const sel)
{
  switch(sel) 
  {
   case REL1: digitalWrite(RELAY_1_PIN, LOW); break; 
   case REL2: digitalWrite(RELAY_2_PIN, LOW); break;
   case REL3: digitalWrite(RELAY_3_PIN, LOW); break;
   case REL4: digitalWrite(RELAY_4_PIN, LOW); break;
   default: break;
  }
}

void RelayShield::turnOff(ERelaySelect const sel)
{
  switch(sel)
  {
   case REL1: digitalWrite(RELAY_1_PIN, HIGH); break; 
   case REL2: digitalWrite(RELAY_2_PIN, HIGH); break;
   case REL3: digitalWrite(RELAY_3_PIN, HIGH); break;
   case REL4: digitalWrite(RELAY_4_PIN, HIGH); break;
   default: break;
  }  
}
