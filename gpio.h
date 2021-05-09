/*
 * util.h
 *
 *  Created on: May 8, 2021
 *      Author: evan
 */

#ifndef GPIO_H_
#define GPIO_H_

// RCGCGPIO General-Purpose Input/Output Run Mode Clock Gating Control
extern unsigned * const GPIO_CLOCK_BASE_REG;

// Base address of GPIO Registers
extern const unsigned  GPIO_A_BASE;
extern const unsigned  GPIO_B_BASE;
extern const unsigned  GPIO_C_BASE;
extern const unsigned  GPIO_D_BASE;
extern const unsigned  GPIO_E_BASE;
extern const unsigned  GPIO_F_BASE;

extern unsigned * const GPIO_BASE[];

// Offsets for GPIO Registers
extern const unsigned GPIO_DIR_OFFSET;
extern const unsigned GPIO_AFSL_OFFSET;
extern const unsigned GPIO_DEN_OFFSET;

// Bit mask values of all GPIO
static inline unsigned gpio_letter_to_bitmask_val(char gpio_letter) { return gpio_letter - 'a' + 1; };
static inline unsigned pin_number_to_bitmask_val(unsigned pin) { return 0x1u << pin; } ;

void initialize_gpio_dout (char gpio_letter, int pin_number);

//Bit Banding
//1. gpio_letter {'a'-'f'}
//2. pin_bitmask {'0x1 - 0xFF} "Bitmask correlating to what pin values you want to change"
//3. value  {0x1 - 0xFF} "Bitmask correlating to what you want the changed pin values to be"
static inline void set_gpio_output(char gpio_letter, unsigned pin_bitmask, unsigned value) {
    *((unsigned *)((unsigned)GPIO_BASE[gpio_letter - 'a'] | pin_bitmask << 2)) = value;
}

#endif /* GPIO_H_ */
