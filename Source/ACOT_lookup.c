//作者：上馬庭
//日付：20180926

#include "ACOT_lookup.h"
#include "ACOT_tail_control.h"
#include "ACOT_run_style.h"
#include "ACOT_ultrasonic_sensor.h"
#include "ACOT_distance_estimation.h"
#include "ACOT_debug.h"
#include "ACOT_game_run.h"
#include "ev3api.h"

int lookup_count=0;

void lookup_in(){
	int sonic_distance=get_sonic_sensor_distance();
	NB_trace_run();
	if(sonic_distance >= LOOKUP_SONIC_MIN && sonic_distance <= LOOKUP_SONIC_MAX){
		tail_lean(LOOKUP_LEAN_ANGLE,LOOKUP_LEAN_POWER, true);
		reset_distance();
		change_game_section();
	}
}

void lookup(){
	NB_fixed_run(LOOKUP_WHEEL_POWER);
	while (get_distance()<LOOKUP_LEAN_RUN_DISTANCE){}
	reset_distance();
	//tslp_tsk(1650);　宮崎タイム
	twin_wheel_stop();
	lookup_count++;
	if(lookup_count==LOOKUP_COUNT_LIMIT){
		change_game_section();
		return;
	}
	turn_run();
}

void lookup_out(){
	NB_fixed_run(-60);
	tail_lean(30,90, false);
	
	tslp_tsk(150);
	twin_wheel_stop();
	tslp_tsk(3000);
	change_game_section();
}

