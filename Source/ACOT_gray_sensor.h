//作者：上馬庭
//日付：20180918

#ifndef ACOT_GRAY_SENSOR_H_
#define ACOT_GRAY_SENSOR_H_

#include "ev3api.h"

#define BLACK_CLOSE 10
#define GRAY_JUDGE_COUNT 50

void set_gray_light(int gray_point);
int is_gray_area();
void gray_sensor_init();

#endif
