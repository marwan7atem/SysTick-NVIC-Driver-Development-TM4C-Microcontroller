/*
 * NVIC.c
 *
 *  Created on: ???/???/????
 *      Author: LENOVO
 */

#include"NVIC.h"

void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num)
{
    if( IRQ_Num>=0 &&  IRQ_Num<32)
    {
        NVIC_EN0_REG |= (1<<IRQ_Num);
    }
    else if (IRQ_Num>=32 &&  IRQ_Num<64)
    {
        IRQ_Num=IRQ_Num-32;
        NVIC_EN1_REG |= (1<<IRQ_Num);
    }
    else if(IRQ_Num>=64 &&  IRQ_Num<96)
    {
        IRQ_Num=IRQ_Num-64;
        NVIC_EN2_REG |= (1<<IRQ_Num);
    }
    else if(IRQ_Num>=96 &&  IRQ_Num<128)
    {
        IRQ_Num=IRQ_Num-96;
        NVIC_EN3_REG |= (1<<IRQ_Num);
    }
    else if(IRQ_Num>=128 &&  IRQ_Num<139)
    {
        IRQ_Num=IRQ_Num-128;
        NVIC_EN4_REG |= (1<<IRQ_Num);
    }
    else
    {
        return;
    }
}
void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num)
{
    if( IRQ_Num>=0 &&  IRQ_Num<32)
        {
            NVIC_DIS0_REG |= (1<<IRQ_Num);
        }
        else if (IRQ_Num>=32 &&  IRQ_Num<64)
        {
            IRQ_Num=IRQ_Num-32;
            NVIC_DIS1_REG |= (1<<IRQ_Num);
        }
        else if(IRQ_Num>=64 &&  IRQ_Num<96)
        {
            IRQ_Num=IRQ_Num-64;
            NVIC_DIS2_REG |= (1<<IRQ_Num);
        }
        else if(IRQ_Num>=96 &&  IRQ_Num<128)
        {
            IRQ_Num=IRQ_Num-96;
            NVIC_DIS3_REG |= (1<<IRQ_Num);
        }
        else if(IRQ_Num>=128 &&  IRQ_Num<139)
        {
            IRQ_Num=IRQ_Num-128;
            NVIC_DIS4_REG |= (1<<IRQ_Num);
        }
        else
        {
            return;
        }
}
void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num,NVIC_IRQPriorityType IRQ_Priority)
{
    if(IRQ_Num % 4==0)
    {
        switch((IRQ_Num-1)/4)
        {
        case (0):
            NVIC_PRI0_REG = (NVIC_PRI0_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (1):
            NVIC_PRI1_REG = (NVIC_PRI1_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (2):
            NVIC_PRI2_REG = (NVIC_PRI2_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (3):
            NVIC_PRI3_REG = (NVIC_PRI3_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (4):
            NVIC_PRI4_REG = (NVIC_PRI4_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (5):
            NVIC_PRI5_REG = (NVIC_PRI5_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (6):
            NVIC_PRI6_REG = (NVIC_PRI6_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (7):
         NVIC_PRI7_REG = (NVIC_PRI7_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
         break;
        case (8):
            NVIC_PRI8_REG = (NVIC_PRI8_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (9):
            NVIC_PRI9_REG = (NVIC_PRI9_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (10):
            NVIC_PRI10_REG = (NVIC_PRI10_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (11):
            NVIC_PRI11_REG = (NVIC_PRI11_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;
        case (12):
            NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & _5_7BITPRIORITY_MASK) | (IRQ_Priority<<_5_7PRIORITY_BITS_POS);
            break;

        }
    }
    else if(IRQ_Num %4 !=0 && (IRQ_Num-2) %4==0)
    {
        switch((IRQ_Num-2)/4)
        {
                case (0):
                    NVIC_PRI0_REG = (NVIC_PRI0_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (1):
                    NVIC_PRI1_REG = (NVIC_PRI1_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (2):
                    NVIC_PRI2_REG = (NVIC_PRI2_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (3):
                    NVIC_PRI3_REG = (NVIC_PRI3_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (4):
                    NVIC_PRI4_REG = (NVIC_PRI4_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (5):
                    NVIC_PRI5_REG = (NVIC_PRI5_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (6):
                    NVIC_PRI6_REG = (NVIC_PRI6_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (7):
                 NVIC_PRI7_REG = (NVIC_PRI7_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                 break;
                case (8):
                    NVIC_PRI8_REG = (NVIC_PRI8_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (9):
                    NVIC_PRI9_REG = (NVIC_PRI9_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (10):
                    NVIC_PRI10_REG = (NVIC_PRI10_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (11):
                    NVIC_PRI11_REG = (NVIC_PRI11_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;
                case (12):
                    NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & _21_23BITPRIORITY_MASK) | (IRQ_Priority<<_21_23PRIORITY_BITS_POS);
                    break;

        }
    }
    else if(IRQ_Num %4 !=0 && (IRQ_Num-3) %4==0 ){
        switch((IRQ_Num-3) /4){
        case(0):
                NVIC_PRI0_REG = (NVIC_PRI0_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(1):
                NVIC_PRI1_REG = (NVIC_PRI1_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(2):
                NVIC_PRI2_REG = (NVIC_PRI2_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(3):
                NVIC_PRI3_REG = (NVIC_PRI3_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(4):
                NVIC_PRI4_REG = (NVIC_PRI4_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(5):
                NVIC_PRI5_REG = (NVIC_PRI5_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(6):
                NVIC_PRI6_REG = (NVIC_PRI6_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(7):
                NVIC_PRI7_REG = (NVIC_PRI7_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(8):
                NVIC_PRI8_REG = (NVIC_PRI8_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(9):
                NVIC_PRI9_REG = (NVIC_PRI9_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(10):
                NVIC_PRI10_REG = (NVIC_PRI10_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(11):
                NVIC_PRI11_REG = (NVIC_PRI11_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        case(12):
            NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG & _29_31BITPRIORITY_MASK) | (IRQ_Priority<<_29_31PRIORITY_BITS_POS);
          break;
        }

        }

}


void NVIC_EnableException(NVIC_ExceptionType Exception_Num)
{
    if(Exception_Num==3)
    {
        NVIC_SYSTEM_SYSHNDCTRL |=(MEM_FAULT_ENABLE_MASK);
    }
    else if(Exception_Num==4)
    {
        NVIC_SYSTEM_SYSHNDCTRL |=(BUS_FAULT_ENABLE_MASK);
    }
    else if(Exception_Num==5)
    {
        NVIC_SYSTEM_SYSHNDCTRL |=(USAGE_FAULT_ENABLE_MASK)
    }
}

void NVIC_DisableException(NVIC_ExceptionType Exception_Num)
{
       if(Exception_Num==3)
        {
            NVIC_SYSTEM_SYSHNDCTRL &=~(MEM_FAULT_ENABLE_MASK);
        }
        else if(Exception_Num==4)
        {
            NVIC_SYSTEM_SYSHNDCTRL &=~(BUS_FAULT_ENABLE_MASK);
        }
        else if(Exception_Num==5)
        {
            NVIC_SYSTEM_SYSHNDCTRL &=~(USAGE_FAULT_ENABLE_MASK)
        }
}
void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority)
{
        if(Exception_Num == 3){
            NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG &  ~(MEM_FAULT_PRIORITY_MASK)) | (Exception_Priority << MEM_FAULT_PRIORITY_BITS_POS);
        }
        else if (Exception_Num == 4){
            NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG &  ~(BUS_FAULT_PRIORITY_MASK)) | (Exception_Priority << BUS_FAULT_PRIORITY_BITS_POS);
        }
        else if (Exception_Num == 5){
            NVIC_SYSTEM_PRI1_REG = (NVIC_SYSTEM_PRI1_REG &  ~(USAGE_FAULT_PRIORITY_MASK)) | (Exception_Priority << USAGE_FAULT_PRIORITY_BITS_POS);
        }
        else if (Exception_Num == 6){
            NVIC_SYSTEM_PRI2_REG = (NVIC_SYSTEM_PRI2_REG &  ~(SVC_PRIORITY_MASK)) | (Exception_Priority << SVC_PRIORITY_BITS_POS);
        }
        else if (Exception_Num == 7){
            NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG &  ~(DEBUG_MONITOR_PRIORITY_MASK)) | (Exception_Priority << DEBUG_MONITOR_PRIORITY_BITS_POS);
        }
        else if (Exception_Num == 8){
            NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG &  ~(PENDSV_PRIORITY_MASK)) | (Exception_Priority << PENDSV_PRIORITY_BITS_POS);
        }
        else if (Exception_Num == 9){
            NVIC_SYSTEM_PRI3_REG = (NVIC_SYSTEM_PRI3_REG &  ~(SYSTICK_PRIORITY_MASK)) | (Exception_Priority << SYSTICK_PRIORITY_BITS_POS);
        }

}
