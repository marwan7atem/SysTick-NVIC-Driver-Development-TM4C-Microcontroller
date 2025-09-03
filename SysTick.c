/*
 * SysTick.c
 *
 *  Created on: ???/???/????
 *      Author: LENOVO
 */

#include"SysTick.h"

static volatile void (*g_CallBackPtr) (void) = null;

void SysTick_Init(uint16 a_TimeInMilliSeconds)
{
    SYSTICK_CTRL_REG    = 0;               /* Disable the SysTick Timer by Clear the ENABLE Bit */
    SYSTICK_RELOAD_REG  = (a_TimeInMilliSeconds*16000)-1;         /* Set the Reload value with 15999999 to count one Second */
    SYSTICK_CURRENT_REG = 0;               /* Clear the Current Register value */
      /* Configure the SysTick Control Register
       * Enable the SysTick Timer (ENABLE = 1)
       * Enable SysTick Interrupt (INTEN = 1)
       * Choose the clock source to be System Clock (CLK_SRC = 1) */
    SYSTICK_CTRL_REG   |= 0x07;
}
void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds)
{
    SYSTICK_CTRL_REG    = 0;               /* Disable the SysTick Timer by Clear the ENABLE Bit */
       SYSTICK_RELOAD_REG  = (a_TimeInMilliSeconds*16000)-1; ;         /* Set the Reload value with 7999999 to count half Second */
       SYSTICK_CURRENT_REG = 0;               /* Clear the Current Register value */
         /* Configure the SysTick Control Register
          * Enable the SysTick Timer (ENABLE = 1)
          * Enable SysTick Interrupt (INTEN = 0)
          * Choose the clock source to be System Clock (CLK_SRC = 1) */
       SYSTICK_CTRL_REG   |= 0x05;
       while(!(SYSTICK_CTRL_REG & (1<<16)));
}
void SysTick_Handler(void)
{
        if(g_CallBackPtr ! =NULL)
        {
            (*g_CallBackPtr)();
        }
}
void SysTick_SetCallBack(volatile void (*Ptr2Func) (void))
{
    g_CallBackPtr=Ptr2Func;
}
void SysTick_Stop(void)
{
    SYSTICK_CTRL_REG &=~(1<<0)&(1<<2);

}
void SysTick_Start(void)
{
    SYSTICK_CTRL_REG |=(1<<0)|(1<<2);

}
void SysTick_DeInit(void)
{
    SYSTICK_RELOAD_REG =0;
    SYSTICK_CURRENT_REG = 0;
    SYSTICK_CTRL_REG=0;
}




