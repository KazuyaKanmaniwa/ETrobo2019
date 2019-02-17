//��ҁF��n��
//���t�F20180921

#ifndef ACOT_LIGHT_SENSOR_H_
#define ACOT_LIGHT_SENSOR_H_

#include "ev3api.h"

//�t�B���^�z��̒���
#define FILTER_LANGTH 5
//���Z���T�̃|�[�g
#define LIGHT_SENSOR_PORT EV3_PORT_3

//���Z���T�[������
int get_reflected_light();
//���ˌ��̎擾�@�Ԃ�l�F���ˌ�
void light_sensor_init();
//���ω��t�B���^�i���ˌ��j�Ԃ�l�F�v�Z�ςݔ��ˌ�
int averaging_filter(int reflected_light);
//�v�Z�ςݔ��ˌ��̎擾�@�Ԃ�l�F�v�Z�ςݔ��ˌ�
int get_cal_reflected_light();

#endif


