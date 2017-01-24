/*
 * main.c
 *
 */
#include <stdint.h>
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "bluetooth.h"


int main(void)
{
	ble_stack_init();

	nrf_gpio_cfg_output(21);

	while (true)
	{
		nrf_gpio_pin_toggle(21);
		nrf_delay_ms(300);
	}
}
