//��ҁF��n��
//���t�F20180921

#include "ACOT_button.h"
#include "ACOT_debug.h"
#include "ev3api.h"

//�{�^��������
void button_init(){
	ev3_sensor_config(BUTTON_PORT,TOUCH_SENSOR);
}

//�{�^�����������܂ő҂�
//���Ӂ��R�[�h�������Ŏ~�܂�
void button_wait_push(){
	while(!ev3_touch_sensor_is_pressed(BUTTON_PORT)){}
	while(ev3_touch_sensor_is_pressed(BUTTON_PORT)){}
}

