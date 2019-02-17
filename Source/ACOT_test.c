
#include "ACOT_test.h"
#include "ACOT_debug.h"
#include "ACOT_light_sensor.h"
#include "ACOT_wheel.h"
#include "ACOT_gyro_sensor.h"
#include "ACOT_balancer.h"
#include "ACOT_PID_control.h"
#include "ACOT_button.h"
#include "ACOT_run_style.h"
#include "ACOT_tail.h"
#include "ACOT_tail_control.h"
#include "ACOT_bluetooth.h"
#include "ACOT_distance_estimation.h"
#include "ACOT_ultrasonic_sensor.h"
#include "ACOT_calibration.h"
#include "ACOT_speed_run.h"
#include "ACOT_start.h"
#include "ACOT_seesaw.h"
#include "ACOT_game_run.h"
#include "ACOT_lookup.h"
#include "ev3api.h"

void running_test_1(){
	all_init();
	debug_tone();
	button_wait_push();
	tail_stand();
	button_wait_push();
	tslp_tsk(1000);
	while(1){
		game_run(GAME_SEESAW);
		tslp_tsk(4);
	}
}

void running_test_2() {
	all_init();
	calibration();
	button_wait_push();
	while (get_distance() < 50) {
		trace_run(LEFT_EDGE, 80, 0.4, 0, 7);
		tslp_tsk(4);
	}
	tail_stol();
	reset_distance();
	while (get_distance() < 50) {
		NB_trace_run();
		tslp_tsk(4);
	}
	tail_lean(20, -5, true);
	tslp_tsk(3000);
	twin_wheel_stop();
	tslp_tsk(3000);
	tail_lean(25, 90, false);
	NB_fixed_run(-60);
	tslp_tsk(200);
	twin_wheel_stop();
}

void running_test_3() {
	all_init();
	calibration();
	tail_stand();
	button_wait_push();
	while (1) {
		debug_disp_write_fixed("a", get_distance(), 10);
		game_run(GAME_LOOKUP);
		tslp_tsk(4);
	}
	
}

void running_test_4() {
	all_init();
	calibration();
	tail_stand();
	debug_file_open("grayLOG.csv");
	PID_init(1, 0, 0);
	int power = 10;
	button_wait_push();
	while (1)
	{
		debug_file_write(get_reflected_light());
		int turn = PID_control(get_reflected_light());
		wheel_run(power - turn, RIGHT_WHEEL);
		wheel_run(power + turn, LEFT_WHEEL);
		tslp_tsk(4);
	}
	twin_wheel_stop();
	debug_file_close();
}

void running_test_5() {
	all_init();
	button_wait_push();
	tail_stol();
}


