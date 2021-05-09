/*
 * gpio.c
 *
 *  Created on: May 9, 2021
 *      Author: evan
 */
#include<gpio.h>
#include<util.h>

// RCGCGPIO General-Purpose Input/Output Run Mode Clock Gating Control
unsigned * const GPIO_CLOCK_BASE_REG = 0x400FE608;

// Base address of GPIO Registers
const unsigned  GPIO_A_BASE = 0x40004000u;
const unsigned  GPIO_B_BASE = 0x40005000u;
const unsigned  GPIO_C_BASE = 0x40006000u;
const unsigned  GPIO_D_BASE = 0x40007000u;
const unsigned  GPIO_E_BASE = 0x40024000u;
const unsigned  GPIO_F_BASE = 0x40025000u;

unsigned * const GPIO_BASE[] = { GPIO_A_BASE, GPIO_B_BASE, GPIO_C_BASE, GPIO_D_BASE, GPIO_E_BASE, GPIO_F_BASE };

// Offsets for GPIO Registers
const unsigned GPIO_DIR_OFFSET = 0x400u;
const unsigned GPIO_AFSL_OFFSET = 0x420u;
const unsigned GPIO_DEN_OFFSET = 0x51Cu;

void initialize_gpio_dout (char gpio_letter, int pin_number){
    //Digital Ouput Config Example
    // AFSEL = 0
    // DIR =1
    // ODR = 0
    // DEN = 1

//  //1. Enable Clock to GPIO B
    *GPIO_CLOCK_BASE_REG |= gpio_letter_to_bitmask_val(gpio_letter);
//  //2. Set Dir to Output GPIODIR for pin 2
    *offset_reg(GPIO_B_BASE, GPIO_DIR_OFFSET) |= pin_number_to_bitmask_val(pin_number);
//  //3. Set Alternate function to standard GPIOAFSEL
    *offset_reg(GPIO_B_BASE, GPIO_AFSL_OFFSET) &= (~pin_number_to_bitmask_val(pin_number));
//  //4. Set Drive Strength  GPIODR2R
    //Defaults to DR2R
//  //5. Set Pull Up GPIOPUR
    //Defaults to Pull up
//  //6. Set DEN for pin 5
    *offset_reg(GPIO_B_BASE, GPIO_DEN_OFFSET) |= pin_number_to_bitmask_val(pin_number);
}



