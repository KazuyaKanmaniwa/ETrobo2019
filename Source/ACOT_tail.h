//��ҁF��n��
//���t�F20180922

#ifndef ACOT_TAIL_H_
#define ACOT_TAIL_H_

#include "ev3api.h"

//�K�����[�^�̃|�[�g
#define TAIL_PORT EV3_PORT_A

//�K�����[�^������
void tail_init();
//�K������]������i�ڕW�p�A�p���[�Atrue or false�j
//3�ڂ̈�����true�Ȃ�ڕW�p�܂ŉ�]���Ă��玟�̏������s���Afalse�Ȃ�I����҂����Ɏ��̏������s��
void tail_spin(int angle,int spin_power,bool_t blocking);
//���[�^�̉�]�p�����Z�b�g����
void reset_tail_counts();

#endif