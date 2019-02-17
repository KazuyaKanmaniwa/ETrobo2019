//作者：上馬庭
//日付：20180921

#include "ACOT_light_sensor.h"
#include "ACOT_debug.h"
#include "ev3api.h"

//フィルタ配列
int filter_array[FILTER_LANGTH];
//フィルタ配列を動かすカウント
int filter_count=0;

//光センサー初期化
void light_sensor_init(){
	ev3_sensor_config(LIGHT_SENSOR_PORT,COLOR_SENSOR);
	for (int i = 0; i < FILTER_LANGTH; i++) {
		filter_array[i] = 0;
	}
}

//反射光の取得　返り値：反射光
int get_reflected_light(){
	return ev3_color_sensor_get_reflect(LIGHT_SENSOR_PORT);
}

//平均化フィルタ（反射光）返り値：計算済み反射光
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

//計算済み反射光の取得　返り値：計算済み反射光
int get_cal_reflected_light() {
	int reflected_light = get_reflected_light();
	return averaging_filter(reflected_light);
}

	
