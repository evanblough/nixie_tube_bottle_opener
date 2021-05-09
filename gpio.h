/*
 * util.h
 *
 *  Created on: May 8, 2021
 *      Author: evan
 */

#ifndef GPIO_H_
#define GPIO_H_

// RCGCGPIO General-Purpose Input/Output Run Mode Clock Gating Control
unsigned * const GPIO_CLOCK_BASE_REG = 0x400FE608;
// Bit mask values of all GPIO
static inline unsigned gpio_letter_to_bitmask_val(char gpio_letter) { return gpio_letter - 'a' + 1; };
static inline unsigned pin_number_to_bitmask_val(unsigned pin) { return 0x1u << pin; } ;
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
//Bit Banding
//1. gpio_letter {'a'-'f'}
//2. pin_bitmask {'0x1 - 0xFF}
//3. value  {0x1 - 0xFF}
static inline unsigned set_gpio_output(char gpio_letter, unsigned pin_bitmask, unsigned value) {
    *((unsigned *)((unsigned)GPIO_BASE[gpio_letter - 'a'] | pin_bitmask << 2)) = value;
}




#endif /* GPIO_H_ */
