//��ҁF��n��
//���t�F20180921

#ifndef ACOT_GYRO_SENSOR_H_
#define ACOT_GYRO_SENSOR_H_

#include "ev3api.h"

#define GYRO_SENSOR_PORT EV3_PORT_4

//�W���C���Z���T�[������
void gyro_sensor_init();
//�e���x�̎擾�@�Ԃ�l�F�e���x
int get_gyro_sensor_rate();
//�p�ʒu�̎擾�@�Ԃ�l�F�p�ʒu
void reset_gyro_sensor_angle();

#endif

