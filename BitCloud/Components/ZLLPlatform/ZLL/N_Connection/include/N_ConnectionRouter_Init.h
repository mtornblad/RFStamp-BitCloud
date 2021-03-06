/*********************************************************************************************//**
\file  

\brief 

\author
    Atmel Corporation: http://www.atmel.com \n
    Support email: avr@atmel.com

  Copyright (c) 2008-2013, Atmel Corporation. All rights reserved.
  Licensed under Atmel's Limited License Agreement (BitCloudTM).

\internal

$Id: N_ConnectionRouter_Init.h 24615 2013-02-27 05:14:24Z arazinkov $

***************************************************************************************************/

#ifndef N_CONNECTIONROUTER_INIT_H
#define N_CONNECTIONROUTER_INIT_H

/***************************************************************************************************
* INCLUDE FILES
***************************************************************************************************/

#include "N_Task.h"
#include "N_Types.h"

/***************************************************************************************************
* C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* EXPORTED FUNCTIONS
***************************************************************************************************/

/** Initialises the component
*/
void N_ConnectionRouter_Init(void);

/** The event handler for the component's task
*/
bool N_ConnectionRouter_EventHandler(N_Task_Event_t evt);

/***************************************************************************************************
* END OF C++ DECLARATION WRAPPER
***************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // N_CONNECTIONROUTER_INIT_H
