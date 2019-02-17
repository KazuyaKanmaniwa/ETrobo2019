//作者：上馬庭
//日付：20180922

#ifndef ACOT_SPEED_RUN_H_
#define ACOT_SPEED_RUN_H_

#include "ev3api.h"

//区間数
#define SPEED_SECTION 8
//パラメータの数
#define PARAMS 4
//パワーの配列場所
#define POWER 0
//P係数の配列場所
#define KP 1
//I係数の配列場所
#define KI 2
//D係数の配列場所
#define KD 3
//コース選択（区間制御用）
#define COURSE 2

#define RIGHT_COURSE 0
#define LEFT_COURSE 1

//スピードコースを走行する（RかLコース）
void speed_run(int course);
#endif

