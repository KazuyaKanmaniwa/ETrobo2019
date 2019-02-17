//製作者：宮﨑
//編集日：2018/9/22

#include "ACOT_ultrasonic_sensor.h"
#include "ACOT_debug.h"
#include "ev3api.h"

//超音波センサー初期化
void ultrasonic_sensor_init(){
	ev3_sensor_config(SONIC_SENSOR_PORT,ULTRASONIC_SENSOR);
}

//センサーから距離をとる
int get_sonic_sensor_distance(){ 
	int distance = 0; 

	distance = ev3_ultrasonic_sensor_get_distance(SONIC_SENSOR_PORT);
	if(distance >= SONOR_DISTANCE_MIN && distance <= SONOR_DISTANCE_MAX){
		return distance;
	}else{
		distance = -1;
		return distance;
	}
}