//��ҁF��n��
//���t�F20180921

#include "ACOT_light_sensor.h"
#include "ACOT_debug.h"
#include "ev3api.h"

//�t�B���^�z��
int filter_array[FILTER_LANGTH];
//�t�B���^�z��𓮂����J�E���g
int filter_count=0;

//���Z���T�[������
void light_sensor_init(){
	ev3_sensor_config(LIGHT_SENSOR_PORT,COLOR_SENSOR);
	for (int i = 0; i < FILTER_LANGTH; i++) {
		filter_array[i] = 0;
	}
}

//���ˌ��̎擾�@�Ԃ�l�F���ˌ�
int get_reflected_light(){
	return ev3_color_sensor_get_reflect(LIGHT_SENSOR_PORT);
}

//���ω��t�B���^�i���ˌ��j�Ԃ�l�F�v�Z�ςݔ��ˌ�
int averaging_filter(int reflected_light) {
	filter_array[filter_count] = reflected_light;
	int light_total = 0;
	for (int i = 0; i < FILTER_LANGTH; i++) {
		light_total += filter_array[i];
	}

	filter_count++;
	if (filter_count == FILTER_LANGTH) {
		filter_count = 0;
	}

	return light_total / FILTER_LANGTH;
}

//�v�Z�ςݔ��ˌ��̎擾�@�Ԃ�l�F�v�Z�ςݔ��ˌ�
int get_cal_reflected_light() {
	int reflected_light = get_reflected_light();
	return averaging_filter(reflected_light);
}

	
