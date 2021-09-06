#include <stdio.h>
#include <gpio.h>
#include <util.h>
#include <flash.h>

//Config

static char gpio_char_min = 'a';
static char gpio_char_max = 'f';
static int k155id1_bcd_input_begin_pin = 0;
static int k155id1_bcd_input_end_pin = 3;


/**
 * hello.c
 */



int main(void)
{
//**************************Init***********************************************//
    //Initialize GPIO B-D, Pins (0-3) to low
    //These are the pin blocks use to drive the logical input to the k155id1 decoder IC
    int k155id1_bcd_input_pin = k155id1_bcd_input_begin_pin;
    for (k155id1_bcd_input_pin = k155id1_bcd_input_begin_pin; k155id1_bcd_input_pin <= k155id1_bcd_input_end_pin ; k155id1_bcd_input_pin++) {
        char gpio_char = gpio_char_min;
        for (gpio_char = gpio_char_min; gpio_char <= gpio_char_max; gpio_char++){
            initialize_gpio_dout(gpio_char, k155id1_bcd_input_pin);
            set_gpio_output(gpio_char,
                            pin_number_to_bitmask_val(k155id1_bcd_input_pin),
                            pin_number_to_bitmask_val(k155id1_bcd_input_pin));
        }
    }
    int i;
    //Cycle all digits on power cycle to check hardware connection
    for (i = 0; i < 10; i++){
        char gpio_char = gpio_char_min;
        for (gpio_char = gpio_char_min; gpio_char <= gpio_char_max; gpio_char++){
            set_gpio_output(gpio_char,0x0F,i);
        }
    }
    //Load count from flash

//**************************Main Loop*****************************************//

    /*unsigned a = get_gpio_input('b', pin_number_to_bitmask_val(2), pin_number_to_bitmask_val(2));
    erase_flash_page(USER_FLASH_BASE_ADDR);
    write_value_to_flash(0x10, USER_FLASH_BASE_ADDR);
    unsigned temp = *offset_reg(USER_FLASH_BASE_ADDR, 0x0);
    erase_flash_page(USER_FLASH_BASE_ADDR);
    write_value_to_flash(0x20, USER_FLASH_BASE_ADDR);
    temp = *offset_reg(USER_FLASH_BASE_ADDR, 0x0);
    erase_flash_page(USER_FLASH_BASE_ADDR);
    write_value_to_flash(0x30, USER_FLASH_BASE_ADDR);
    temp = *offset_reg(USER_FLASH_BASE_ADDR, 0x0);
*/
	while(1);
	
	return 0;
}
