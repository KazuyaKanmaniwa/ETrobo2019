//作者：上馬庭
//日付：20180923

#ifndef ACOT_WHEEL_H_
#define ACOT_WHEEL_H_

#include "ev3api.h"

#define RIGHT_WHEEL 0
#define LEFT_WHEEL 1
#define BRAKE 0
#define FLOAT 1
//右車輪モータのポート
#define RIGHT_WHEEL_PORT EV3_PORT_B
//左車輪モータのポート
#define LEFT_WHEEL_PORT EV3_PORT_C

//左右車輪モータの初期化
void twin_wheel_init();
//車輪を回転させる（パワー、左右
void wheel_run(int power,int LorR);
void wheel_stop(int LorR,int BorF);
//車輪を止める（左右）
void reset_wheel_counts(int LroR);
//車輪の回転角をリセットする（左右）
int32_t get_wheel_counts(int LorR);
//車輪の回転角を取得する（左右）　返り値：車輪の回転角

#endif


