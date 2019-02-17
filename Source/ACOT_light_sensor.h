//作者：上馬庭
//日付：20180921

#ifndef ACOT_LIGHT_SENSOR_H_
#define ACOT_LIGHT_SENSOR_H_

#include "ev3api.h"

//フィルタ配列の長さ
#define FILTER_LANGTH 5
//光センサのポート
#define LIGHT_SENSOR_PORT EV3_PORT_3

//光センサー初期化
int get_reflected_light();
//反射光の取得　返り値：反射光
void light_sensor_init();
//平均化フィルタ（反射光）返り値：計算済み反射光
int averaging_filter(int reflected_light);
//計算済み反射光の取得　返り値：計算済み反射光
int get_cal_reflected_light();

#endif


