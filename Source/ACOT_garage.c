//作者：上馬庭
//日付：20180926

#include "ACOT_garage.h"
#include "ACOT_run_style.h"
#include "ACOT_distance_estimation.h"
#include "ACOT_debug.h"
#include "ACOT_game_run.h"
#include "ev3api.h"

void garage_in(){
	NB_trace_run();
	if(get_distance()>GARAGE_DISTANCE){
		reset_distance();
		twin_wheel_stop();
		change_game_section();
	}
}


