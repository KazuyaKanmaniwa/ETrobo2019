//作者：上馬庭
//日付：20180921

#ifndef ACOT_BALANCER_H_
#define ACOT_BALANCER_H_

#include "ev3api.h"

#define GYRO_OFFSET 0

//バランサー初期化
void acot_balancer_init();
//車体が倒れた判定 返り値：true,false
int is_balancer_down();
//バランサー制御（前進するパワー、PIDからの計算値、右車輪の回転角、左車輪の回転角）返り値：車輪のパワー配列
//倒立振子の計算をして車輪のパワーを導く
int *acot_balance_control(signed char forward, signed char turn, int32_t wheel_counts_R, int32_t wheel_counts_L);
//バランサーの勢い抑制（左車輪のパワー、右車輪のパワー、左車輪の回転角、右車輪の回転角）
void backlash_cancel(signed char wheel_power_L, signed char wheel_power_R, int32_t *wheel_counts_L, int32_t *wheel_counts_R);

#endif

