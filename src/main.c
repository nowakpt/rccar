/*
 * main.c
 *
 */
#include <stdint.h>
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "bluetooth.h"
#include "app_timer.h"
#include "app_timer_config.h"


int main(void)
{
	APP_TIMER_INIT(APP_TIMER_PRESCALER, APP_TIMER_OP_QUEUE_SIZE, APP_TIMER_SCHEDULER_FUNC);
	ble_stack_init();

	nrf_gpio_cfg_output(21);

	while (true)
	{
		nrf_gpio_pin_toggle(21);
		nrf_delay_ms(300);
	}
}
