//作者：上馬庭
//日付：20180923

#include "ACOT_seesaw.h"
#include "ACOT_gyro_sensor.h"
#include "ACOT_run_style.h"
#include "ACOT_tail_control.h"
#include "ACOT_debug.h"
#include "ACOT_game_run.h"
#include "ev3api.h"

int invation_lean_power[]={50,-100};
int invation_lean_angle[]={30,25};

int seesaw_gyro_angle[SEESAW_SECTION]={55,30,30};
int seesaw_lean_angle[SEESAW_SECTION]={38,60,45};
int seesaw_lean_power[SEESAW_SECTION]={-50,50,-50};
int seesaw_slip_power[SEESAW_SECTION]={100,-100,100};
int seesaw_slip_time[SEESAW_SECTION]={200,180,160};
int seesaw_run_power[SEESAW_SECTION]={10,-10,10};
int seesaw_gyro_factor[SEESAW_SECTION]={1,-1,1};

void seesaw_in(){
	NB_fixed_run(INVATION_LOW_POWER);
	if(get_gyro_sensor_rate()>INVATION_GYRO_RATE){
		debug_tone();
		tail_lean(invation_lean_angle[0],invation_lean_power[0],true);
		NB_fixed_run(INVATION_HIGH_POWER);
		tslp_tsk(200);
		tail_lean(invation_lean_angle[1],invation_lean_power[1],true);
		tslp_tsk(150);
		twin_wheel_stop();
		tslp_tsk(3000);
		gyro_sensor_init();
		change_game_section();
	}
}

void seesaw(){
	if(seesaw_gyro_factor[seesaw_section_count]*get_gyro_sensor_rate()>seesaw_gyro_angle[seesaw_section_count]){
		debug_tone();
		tail_lean(seesaw_lean_angle[seesaw_section_count],seesaw_lean_power[seesaw_section_count],false);
		NB_fixed_run(seesaw_slip_power[seesaw_section_count]);
		tslp_tsk(seesaw_slip_time[seesaw_section_count]);

		twin_wheel_stop();
		tslp_tsk(2000);
		seesaw_section_count++;
	}else{
		NB_fixed_run(seesaw_run_power[seesaw_section_count]);
	}

	if(seesaw_section_count==SEESAW_SECTION){
		twin_wheel_stop();
		tslp_tsk(1000);
		change_game_section();
	}
}

void seesaw_out(){
	NB_fixed_run(100);
	tslp_tsk(600);
	twin_wheel_stop();
	change_game_section();
}

