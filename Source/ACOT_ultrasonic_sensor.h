//����ҁF�{��
//�ҏW���F2018/9/22

#ifndef ACOT_ULTRASONIC_SENSOR_H_
#define ACOT_ULTRASONIC_SENSOR_H_

#include"ev3api.h"

//�Z���T�[�����鋗���̍ő�l
#define SONOR_DISTANCE_MAX 15
//�Z���T�[�����鋗���̍ŏ��l
#define SONOR_DISTANCE_MIN 5
//�����g�Z���T�[�̃|�[�g
#define SONIC_SENSOR_PORT EV3_PORT_2

//�����g�Z���T�[������
void ultrasonic_sensor_init();
//�Z���T�[���狗�����Ƃ�
int get_sonic_sensor_distance();

#endif