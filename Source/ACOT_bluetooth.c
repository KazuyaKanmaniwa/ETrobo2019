
#include "ACOT_bluetooth.h"
#include "ACOT_debug.h"
#include "ev3api.h"
#include<stdio.h>

FILE *bluetooth_file=NULL;

//Bluetooth�������ݒ�
void bluetooth_init() {
	bluetooth_file = ev3_serial_open_file(BT_SERIAL_PORT);
	assert(bluetooth_file != NULL);
}

//�ʐM���󂯎��������@�Ԃ�l�Ftrue,false
int is_bluetooth_signal() {
	uint8_t command = fgetc(bluetooth_file);
	if (command == BT_START_COMMAND) {
		return 1;
	}
	else {
		return 0;
	}
}
