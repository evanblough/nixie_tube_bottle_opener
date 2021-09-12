/*
 * timer.c
 *
 *  Created on: Sep 5, 2021
 *      Author: evan
 */

#include <util.h>

unsigned const RCGCTIMER_BASE_ADDR = 0x400FE604U;
unsigned const TIMER0_BASE_ADDR = 0x40030000U;
unsigned const TIMER_CTL_OFFSET = 0x00CU;
unsigned const TIMER_A_MODE_OFFSET = 0x004U;
unsigned const TIMER_A_INTERVAL_OFFSET = 0x028U;
//unsigned const TIMER_A_VAL_OFFSET = 0x048U;
unsigned const TIMER_A_VAL_OFFSET = 0x050U;
unsigned const TIMER_A_PRESCALE = 0x038U;

void poll_timer(int seconds){
    //Enable RCGCTIMER0
    *offset_reg(RCGCTIMER_BASE_ADDR, 0)|=0x1;
    //1. Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making any changes
    *offset_reg(TIMER0_BASE_ADDR, TIMER_CTL_OFFSET)&=0xFFFFFFFE;
    //2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000.
    *offset_reg(TIMER0_BASE_ADDR, 0x0)&=0x00000000;
    //3. configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR) 0x2=periodic
    *offset_reg(TIMER0_BASE_ADDR, TIMER_A_MODE_OFFSET)&=0xFFFFFFC;
    *offset_reg(TIMER0_BASE_ADDR, TIMER_A_MODE_OFFSET)|=0x2;
    //4. Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR)
    *offset_reg(TIMER0_BASE_ADDR, TIMER_A_INTERVAL_OFFSET)=0xFFFFFF;
    //5. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.
    *offset_reg(TIMER0_BASE_ADDR, TIMER_CTL_OFFSET)|=0x1;
    unsigned cntr_val = *offset_reg(TIMER0_BASE_ADDR, TIMER_A_VAL_OFFSET);
    unsigned prev_cntr_val = cntr_val;
    while(prev_cntr_val >= cntr_val) {
        prev_cntr_val = cntr_val;
        cntr_val = *offset_reg(TIMER0_BASE_ADDR, TIMER_A_VAL_OFFSET);
    }
}

