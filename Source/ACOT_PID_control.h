//��ҁF��n��
//���t�F20180921

#ifndef ACOT_PID_CONTROL_H_
#define ACOT_PID_CONTROL_H_

#include "ev3api.h"

//PID�̌W���̏������iP�W���AI�W���AD�W���j
void PID_init(double Kp,double Ki,double Kd);
//�ڕW�l�ݒ�i�ڕW�l�j
void set_PID_middle_light(int middle_light);
//PID����i���ˌ��j�@�Ԃ�l�F����l
int PID_control(int refrect_light);
double get_middle_light();

#endif

