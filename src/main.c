/*
 * main.c
 *
 */
#include <stdint.h>
#include "nrf_gpio.h"
#include "nrf_delay.h"


int main(void)
{
	nrf_gpio_cfg_output(21);

	while (true)
	{
		nrf_gpio_pin_toggle(21);
		nrf_delay_ms(300);
	}
}
