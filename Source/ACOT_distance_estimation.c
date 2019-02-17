//編集者：宮﨑
//編集日：2018/9/23

#include "ACOT_distance_estimation.h"
#include "ACOT_debug.h"
#include "ev3api.h"
#include "ACOT_wheel.h"

//削除された距離
int garbage_distance = 0;

//移動距離を取得する 返り値：移動距離
int get_distance(){
	double left_angle = 0;
	double right_angle = 0;
	double left_distance = 0;
	double right_distance = 0;
	int perfect_distance = 0;

	left_angle = get_wheel_counts(LEFT_WHEEL);
	right_angle = get_wheel_counts(RIGHT_WHEEL);
	
	left_distance = (DIAMETER * PI) * (left_angle / 360);
	right_distance = (DIAMETER * PI) * (right_angle / 360);

	perfect_distance = (left_distance + right_distance) / 2;
	return perfect_distance-garbage_distance;
}

//移動距離をリセットする
void reset_distance() {
	garbage_distance += get_distance();
}