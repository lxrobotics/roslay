/**
 * \author Alexander Entinger, MSc
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
