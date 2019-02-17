//作者：上馬庭
//日付：20180921

#include "ACOT_gyro_sensor.h"
#include "ACOT_debug.h"
#include "ev3api.h"

//ジャイロセンサー初期化
void gyro_sensor_init(){
	ev3_sensor_config(GYRO_SENSOR_PORT,GYRO_SENSOR);
	reset_gyro_sensor_angle();
}

//各速度の取得　返り値：各速度
int get_gyro_sensor_rate(){
	return ev3_gyro_sensor_get_rate(GYRO_SENSOR_PORT);
}

//角位置の取得　返り値：角位置
void reset_gyro_sensor_angle(){
	ev3_gyro_sensor_reset(GYRO_SENSOR_PORT);
}

