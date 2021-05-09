#include <stdio.h>
#include <gpio.h>
#include <util.h>


/**
 * hello.c
 */


int main(void)
{

    initialize_gpio_dout('b', 2);
    set_gpio_output('b', pin_number_to_bitmask_val(2), pin_number_to_bitmask_val(2));

	while(1);
	
	return 0;
}
