/*
 * bluetooth.c
 */
#include "bluetooth.h"
#include "nrf_error.h"
#include "softdevice_handler.h"
#include "app_error.h"


#define CENTRAL_LINKS_COUNT              0
#define PERIPHERAL_LINKS_COUNT           1


static void ble_evt_handler(ble_evt_t * p_ble_evt)
{

}

static void sys_evt_handler(uint32_t evt_id)
{

}

static inline void init_softdevice(void)
{
	uint32_t retval;
	ble_enable_params_t ble_enable_params;
	nrf_clock_lf_cfg_t clock_config = {
		.source        = NRF_CLOCK_LF_SRC_XTAL,
		.rc_ctiv       = 0,
		.rc_temp_ctiv  = 0,
		.xtal_accuracy = NRF_CLOCK_LF_XTAL_ACCURACY_50_PPM};

	SOFTDEVICE_HANDLER_INIT(&clock_config, NULL);

	retval = softdevice_enable_get_default_config(CENTRAL_LINKS_COUNT, PERIPHERAL_LINKS_COUNT, &ble_enable_params);
	APP_ERROR_CHECK(retval);

	retval = softdevice_enable(&ble_enable_params);
	APP_ERROR_CHECK(retval);
}

static inline void init_evt_handlers(ble_evt_handler_t ble_evt_handler, sys_evt_handler_t sys_evt_handler)
{
	uint32_t retval;

	retval = softdevice_ble_evt_handler_set(ble_evt_handler);
	APP_ERROR_CHECK(retval);

	retval = softdevice_sys_evt_handler_set(sys_evt_handler);
	APP_ERROR_CHECK(retval);
}

static inline void init_gap_params(void)
{
	//todo implement
}

static inline void init_conn_params(void)
{
	//todo implement
}

void ble_stack_init(void)
{
	init_softdevice();
	init_evt_handlers(ble_evt_handler, sys_evt_handler);
	init_gap_params();
	init_conn_params();
}

void ble_services_init(void)
{
	//todo implement
}
