//作者：上馬庭
//日付：20180921

#ifndef ACOT_PID_CONTROL_H_
#define ACOT_PID_CONTROL_H_

#include "ev3api.h"

//PIDの係数の初期化（P係数、I係数、D係数）
void PID_init(double Kp,double Ki,double Kd);
//目標値設定（目標値）
void set_PID_middle_light(int middle_light);
//PID制御（反射光）　返り値：制御値
int PID_control(int refrect_light);
double get_middle_light();

#endif

