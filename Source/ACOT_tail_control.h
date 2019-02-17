//作者：上馬庭
//日付：20180928

#ifndef ACOT_TAIL_CONTROL_H_
#define ACOT_TAIL_CONTROL_H_

#include "ev3api.h"

//尻尾パワー大
#define TAIL_POWER_HIGH 80
//尻尾パワー小
#define TAIL_POWER_LOW 20
//立つときの尻尾の角度
#define TAIL_STAND_ANGLE 95
//stol()の立つ尻尾の角度
#define STOL_STAND_ANGLE 75
//stol()のちょっと前に進むパワー
#define STOL_WHEEL_POWER 80
//リターンするときの尻尾の角度
#define TAIL_RETURN_ANGLE -180
#define LTOS_LEAN_ANGLE 31

//尻尾制御初期化
void tail_control_init();
//立つ
void tail_stand();
//傾ける（lean_spin()と同じパラメータ）
void tail_lean(int lean_angle, int lean_power, bool_t lean_pass);
//たち状態から傾き状態へ stan to lean
void tail_stol();
//尻尾を最大まで上げる
void tail_return();
void tail_ltos();

#endif


