//作者：上馬庭
//日付：20180921

#include "ACOT_button.h"
#include "ACOT_debug.h"
#include "ev3api.h"

//ボタン初期化
void button_init(){
	ev3_sensor_config(BUTTON_PORT,TOUCH_SENSOR);
}

//ボタンが押されるまで待つ
//注意＊コードがここで止まる
void button_wait_push(){
	while(!ev3_touch_sensor_is_pressed(BUTTON_PORT)){}
	while(ev3_touch_sensor_is_pressed(BUTTON_PORT)){}
}

