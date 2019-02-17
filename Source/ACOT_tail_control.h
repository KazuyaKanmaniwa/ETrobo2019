//��ҁF��n��
//���t�F20180928

#ifndef ACOT_TAIL_CONTROL_H_
#define ACOT_TAIL_CONTROL_H_

#include "ev3api.h"

//�K���p���[��
#define TAIL_POWER_HIGH 80
//�K���p���[��
#define TAIL_POWER_LOW 20
//���Ƃ��̐K���̊p�x
#define TAIL_STAND_ANGLE 95
//stol()�̗��K���̊p�x
#define STOL_STAND_ANGLE 75
//stol()�̂�����ƑO�ɐi�ރp���[
#define STOL_WHEEL_POWER 80
//���^�[������Ƃ��̐K���̊p�x
#define TAIL_RETURN_ANGLE -180
#define LTOS_LEAN_ANGLE 31

//�K�����䏉����
void tail_control_init();
//����
void tail_stand();
//�X����ilean_spin()�Ɠ����p�����[�^�j
void tail_lean(int lean_angle, int lean_power, bool_t lean_pass);
//������Ԃ���X����Ԃ� stan to lean
void tail_stol();
//�K�����ő�܂ŏグ��
void tail_return();
void tail_ltos();

#endif


