//作者：上馬庭
//日付：20180912

#ifndef ACOT_BUTTON_H_
#define ACOT_BUTTON_H_

#include "ev3api.h"

//ボタンのポート
#define BUTTON_PORT EV3_PORT_1

//ボタン初期化
void button_init();
//ボタンが押されるまで待つ
//注意＊コードがここで止まる
void button_wait_push();

#endif

