//製作者：宮﨑
//編集日：2018/9/23

#ifndef ACOT_DISTANCD_ESTIMATION_H_
#define ACOT_DISTANCD_ESTIMATION_H_

#include"ev3api.h"

//円周率
#define PI 3.14
//車輪の直径
#define DIAMETER 10

//移動距離を取得する 返り値：移動距離
int get_distance();

//移動距離をリセットする
//注意＊モータの回転角はそのまま
void reset_distance();

#endif