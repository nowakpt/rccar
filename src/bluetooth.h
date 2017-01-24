/*
 * bluetooth.h
 */
#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
#include <stdint.h>

// initialize BLE stack
void ble_stack_init(void);


// initialize GATT services
void ble_services_init(void);


#endif /* BLUETOOTH_H_ */
