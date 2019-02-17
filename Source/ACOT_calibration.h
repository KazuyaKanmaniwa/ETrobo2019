//作者：上馬庭
//日付：20180921

#ifndef ACOT_CALIBRATION_H_
#define ACOT_CALIBRATION_H_

#include "ev3api.h"

//すべての初期化
//プログラムの一番最初に持ってくる
void calibration();
//キャリブレーション設定
//白黒灰の値をとってPIDの目標値を設定する
void all_init();

#endif

