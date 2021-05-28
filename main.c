#include <stdio.h>
#include <gpio.h>
#include <util.h>
#include <flash.h>


/**
 * hello.c
 */



int main(void)
{

    initialize_gpio_din('b', 2);
    unsigned a = get_gpio_input('b', pin_number_to_bitmask_val(2), pin_number_to_bitmask_val(2));
    erase_flash_page(USER_FLASH_BASE_ADDR);
    write_value_to_flash(0x10, USER_FLASH_BASE_ADDR);
    unsigned temp = *offset_reg(USER_FLASH_BASE_ADDR, 0x0);
    erase_flash_page(USER_FLASH_BASE_ADDR);
    write_value_to_flash(0x20, USER_FLASH_BASE_ADDR);
    temp = *offset_reg(USER_FLASH_BASE_ADDR, 0x0);
    erase_flash_page(USER_FLASH_BASE_ADDR);
    write_value_to_flash(0x30, USER_FLASH_BASE_ADDR);
    temp = *offset_reg(USER_FLASH_BASE_ADDR, 0x0);

	while(1);
	
	return 0;
}
