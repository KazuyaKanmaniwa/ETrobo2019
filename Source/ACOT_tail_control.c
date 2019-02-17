//��ҁF��n��
//���t�F20180928

#include "ACOT_tail_control.h"
#include "ACOT_tail.h"
#include "ACOT_run_style.h"
#include "ev3api.h"

//�K�����䏉����
void tail_control_init(){
	tail_init();
	tail_return();
	tslp_tsk(500);
	reset_tail_counts();
}

//����
void tail_stand(){
	tail_spin(TAIL_STAND_ANGLE,TAIL_POWER_HIGH,false);
	reset_tail_counts();
}

//�X����ilean_spin()�Ɠ����p�����[�^�j
void tail_lean(int lean_angle,int lean_power,bool_t lean_pass){
	tail_spin(lean_angle,lean_power,lean_pass);
	reset_tail_counts();
}


//������Ԃ���X����Ԃ� stand to lean
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

//�K�����ő�܂ŏグ��
void tail_return() {
	tail_spin(TAIL_RETURN_ANGLE, TAIL_POWER_HIGH,false);
}

