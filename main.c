#include <stdio.h>
#include <gpio.h>


/**
 * hello.c
 */
static inline unsigned * offset_reg (unsigned base, unsigned offset) { return (unsigned *) (base | offset); };


int main(void)
{
	//Digital Ouput Config Example
	// AFSEL = 0
	// DIR =1
	// ODR = 0
	// DEN = 1

//	//1. Enable Clock to GPIO B
    *GPIO_CLOCK_BASE_REG |= gpio_letter_to_bitmask_val('b');
//	//2. Set Dir to Output GPIODIR for pin 2
    *offset_reg(GPIO_B_BASE, GPIO_DIR_OFFSET) |= pin_number_to_bitmask_val(2);
//	//3. Set Alternate function to standard GPIOAFSEL
    *offset_reg(GPIO_B_BASE, GPIO_AFSL_OFFSET) &= (~pin_number_to_bitmask_val(2));
//	//4. Set Drive Strength  GPIODR2R
    //Defaults to DR2R
//	//5. Set Pull Up GPIOPUR
    //Defaults to Pull up
//	//6. Set DEN for pin 5
    *offset_reg(GPIO_B_BASE, GPIO_DEN_OFFSET) |= pin_number_to_bitmask_val(2);
//	//7. Set GPIO Data
    set_gpio_output('b', pin_number_to_bitmask_val(2), pin_number_to_bitmask_val(2));

	while(1);
	
	return 0;
}
