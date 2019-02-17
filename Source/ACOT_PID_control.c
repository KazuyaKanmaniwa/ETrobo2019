//��ҁF��n��
//���t�F20180921

#include "ACOT_PID_control.h"
#include "ACOT_debug.h"
#include "ev3api.h"

//���W��
double PID_Kp;
//�ϕ��W��
double PID_Ki;
//�����W��
double PID_Kd;

//�ڕW�l�Ƃ̍���
double p_error;
//�~�ς��ꂽ����
double i_error;
//���O�̌덷�Ƃ̍���
double d_error;
//�O��̖ڕW�l�Ƃ̌덷
double preview_error;

//�ڕW�l
double PID_middle_light;

//�ŏ��̐ϕ��v�Z�̂��߂̃t���O
int is_first_call=1;

//PID�̌W���̏������iP�W���AI�W���AD�W���j
void PID_init(double Kp,double Ki,double Kd){
	PID_Kp=Kp;
	PID_Ki=Ki;
	PID_Kd=Kd;
}

//�ڕW�l�ݒ�
void set_PID_middle_light(int middle_light){
	PID_middle_light=middle_light;
}

//PID����i���ˌ��j�@�Ԃ�l�F����l
int PID_control(int refrect_light){
	double error=PID_middle_light-refrect_light;
	if(is_first_call){
		is_first_call=0;
		d_error=error;
		preview_error=error;
	}
	else{
		d_error=error-preview_error;
		preview_error=error;
	}
	p_error=error;
	i_error+=error;

	return PID_Kp*p_error+PID_Ki*i_error+PID_Kd*d_error;
}


double get_middle_light() {
	return PID_middle_light;
}
		
