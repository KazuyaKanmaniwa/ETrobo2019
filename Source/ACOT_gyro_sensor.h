//作者：上馬庭
//日付：20180921

#ifndef ACOT_GYRO_SENSOR_H_
#define ACOT_GYRO_SENSOR_H_

#include "ev3api.h"

#define GYRO_SENSOR_PORT EV3_PORT_4

//ジャイロセンサー初期化
void gyro_sensor_init();
//各速度の取得　返り値：各速度
int get_gyro_sensor_rate();
//角位置の取得　返り値：角位置
void reset_gyro_sensor_angle();

#endif

