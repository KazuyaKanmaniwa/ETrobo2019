//作者：上馬庭
//日付：20180922

#ifndef ACOT_TAIL_H_
#define ACOT_TAIL_H_

#include "ev3api.h"

//尻尾モータのポート
#define TAIL_PORT EV3_PORT_A

//尻尾モータ初期化
void tail_init();
//尻尾を回転させる（目標角、パワー、true or false）
//3つ目の引数はtrueなら目標角まで回転してから次の処理を行い、falseなら終了を待たずに次の処理を行う
void tail_spin(int angle,int spin_power,bool_t blocking);
//モータの回転角をリセットする
void reset_tail_counts();

#endif