/*
 * SysTick.h
 *
 *  Created on: ???/???/????
 *      Author: LENOVO
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
#include"std_types.h"
#include "tm4c123gh6pm_registers.h"

/* Initialize the SysTick timer with the specified time in milliseconds
using interrupts. This function is used to setup the timer to generate periodic
interrupts every specified time in milliseconds.*/

void SysTick_Init(uint16 a_TimeInMilliSeconds);

/* Initialize the SysTick timer with the specified time in milliseconds
using polling or busy-wait technique. The function should exit when the time is
elapsed and stops the timer at the end*/

void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds);


void SysTick_Handler(void);             // Handler for SysTick interrupt use to call the call-back function

void SysTick_SetCallBack(volatile void (*Ptr2Func) (void));   // Function to setup the SysTick Timer call back to be executed in SysTick Handler.

void SysTick_Stop(void); //Stop the SysTick timer

void SysTick_Start(void); //Start/Resume the SysTick timer.

void SysTick_DeInit(void); //Function to De-initialize the SysTick Timer.





#endif /* SYSTICK_H_ */
