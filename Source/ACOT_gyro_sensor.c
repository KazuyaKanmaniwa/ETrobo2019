//��ҁF��n��
//���t�F20180921

#include "ACOT_gyro_sensor.h"
#include "ACOT_debug.h"
#include "ev3api.h"

//�W���C���Z���T�[������
void gyro_sensor_init(){
	ev3_sensor_config(GYRO_SENSOR_PORT,GYRO_SENSOR);
	reset_gyro_sensor_angle();
}

//�e���x�̎擾�@�Ԃ�l�F�e���x
int get_gyro_sensor_rate(){
	return ev3_gyro_sensor_get_rate(GYRO_SENSOR_PORT);
}

//�p�ʒu�̎擾�@�Ԃ�l�F�p�ʒu
void reset_gyro_sensor_angle(){
	ev3_gyro_sensor_reset(GYRO_SENSOR_PORT);
}

