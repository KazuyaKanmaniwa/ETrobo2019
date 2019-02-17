//��ҁF��n��
//���t�F20180921

#ifndef ACOT_BALANCER_H_
#define ACOT_BALANCER_H_

#include "ev3api.h"

#define GYRO_OFFSET 0

//�o�����T�[������
void acot_balancer_init();
//�ԑ̂��|�ꂽ���� �Ԃ�l�Ftrue,false
int is_balancer_down();
//�o�����T�[����i�O�i����p���[�APID����̌v�Z�l�A�E�ԗւ̉�]�p�A���ԗւ̉�]�p�j�Ԃ�l�F�ԗւ̃p���[�z��
//�|���U�q�̌v�Z�����Ďԗւ̃p���[�𓱂�
int *acot_balance_control(signed char forward, signed char turn, int32_t wheel_counts_R, int32_t wheel_counts_L);
//�o�����T�[�̐����}���i���ԗւ̃p���[�A�E�ԗւ̃p���[�A���ԗւ̉�]�p�A�E�ԗւ̉�]�p�j
void backlash_cancel(signed char wheel_power_L, signed char wheel_power_R, int32_t *wheel_counts_L, int32_t *wheel_counts_R);

#endif

