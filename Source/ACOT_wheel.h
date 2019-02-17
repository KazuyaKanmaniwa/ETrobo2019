//��ҁF��n��
//���t�F20180923

#ifndef ACOT_WHEEL_H_
#define ACOT_WHEEL_H_

#include "ev3api.h"

#define RIGHT_WHEEL 0
#define LEFT_WHEEL 1
#define BRAKE 0
#define FLOAT 1
//�E�ԗփ��[�^�̃|�[�g
#define RIGHT_WHEEL_PORT EV3_PORT_B
//���ԗփ��[�^�̃|�[�g
#define LEFT_WHEEL_PORT EV3_PORT_C

//���E�ԗփ��[�^�̏�����
void twin_wheel_init();
//�ԗւ���]������i�p���[�A���E
void wheel_run(int power,int LorR);
void wheel_stop(int LorR,int BorF);
//�ԗւ��~�߂�i���E�j
void reset_wheel_counts(int LroR);
//�ԗւ̉�]�p�����Z�b�g����i���E�j
int32_t get_wheel_counts(int LorR);
//�ԗւ̉�]�p���擾����i���E�j�@�Ԃ�l�F�ԗւ̉�]�p

#endif


