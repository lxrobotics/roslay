/**
 * \author Alexander Entinger, MSc
 */

#ifndef RELAY_SHIELD_H_ 
#define RELAY_SHIELD_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <Arduino.h>

/**************************************************************************************
 * TYPEDEFS
 **************************************************************************************/

typedef enum {REL1, REL2, REL3, REL4} ERelaySelect;

/**************************************************************************************
 * CLASS DEFINITION
 **************************************************************************************/

class RelayShield 
{

public:

   static void begin();
   
   static void turnOn (ERelaySelect const sel);
   static void turnOff(ERelaySelect const sel);  
};

#endif
