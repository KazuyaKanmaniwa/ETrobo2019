//製作者：宮﨑
//編集日：2018/9/22

#ifndef ACOT_ULTRASONIC_SENSOR_H_
#define ACOT_ULTRASONIC_SENSOR_H_

#include"ev3api.h"

//センサーが測る距離の最大値
#define SONOR_DISTANCE_MAX 15
//センサーが測る距離の最小値
#define SONOR_DISTANCE_MIN 5
//超音波センサーのポート
#define SONIC_SENSOR_PORT EV3_PORT_2

//超音波センサー初期化
void ultrasonic_sensor_init();
//センサーから距離をとる
int get_sonic_sensor_distance();

#endif