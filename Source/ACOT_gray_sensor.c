//作者：上馬庭
//日付：20180918

#include "ACOT_gray_sensor.h"
#include "ACOT_light_sensor.h"
#include "ACOT_PID_control.h"
#include "ACOT_debug.h"

double PID_ahead;
int gray_light;
int gray_count=0;

void set_gray_light(int gray_point){
	gray_light=gray_point;
}

void gray_sensor_init(){
	PID_ahead=get_middle_light();
	set_PID_middle_light(BLACK_CLOSE);
}

int is_gray_area(){
	int reflected_light = get_reflected_light();
	if(reflected_light>gray_light){
		gray_count++;
	}

	debug_disp_write_fixed("gray_count", gray_count, 40);

	if(gray_count>GRAY_JUDGE_COUNT){
		return 1;
		set_PID_middle_light(PID_ahead);
	}else{
		return 0;
	}
}

