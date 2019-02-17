//作者：上馬庭
//日付：20180928

#include "ACOT_tail_control.h"
#include "ACOT_tail.h"
#include "ACOT_run_style.h"
#include "ev3api.h"

//尻尾制御初期化
void tail_control_init(){
	tail_init();
	tail_return();
	tslp_tsk(500);
	reset_tail_counts();
}

//立つ
void tail_stand(){
	tail_spin(TAIL_STAND_ANGLE,TAIL_POWER_HIGH,false);
	reset_tail_counts();
}

//傾ける（lean_spin()と同じパラメータ）
void tail_lean(int lean_angle,int lean_power,bool_t lean_pass){
	tail_spin(lean_angle,lean_power,lean_pass);
	reset_tail_counts();
}


//たち状態から傾き状態へ stand to lean
void tail_stol(){
	
	tail_lean(STOL_STAND_ANGLE,TAIL_POWER_HIGH,false);
	NB_fixed_run(STOL_WHEEL_POWER);
	tslp_tsk(100);
	twin_wheel_stop_float();
	tslp_tsk(2000);
	reset_tail_counts();
	tail_ltos();
}

void tail_ltos() {
	NB_fixed_run(-1*STOL_WHEEL_POWER);
	tail_lean(LTOS_LEAN_ANGLE, TAIL_POWER_LOW, false);
	
	tslp_tsk(150);
	twin_wheel_stop();
	tslp_tsk(2000);
	reset_tail_counts();
}

//尻尾を最大まで上げる
void tail_return() {
	tail_spin(TAIL_RETURN_ANGLE, TAIL_POWER_HIGH,false);
}

