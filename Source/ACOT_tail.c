//作者：上馬庭
//日付：20180922

#include "ACOT_tail.h"
#include "ev3api.h"
#include "ACOT_wheel.h"

//尻尾モータ初期化
void tail_init(){
	ev3_motor_config(TAIL_PORT,LARGE_MOTOR);
}

//尻尾を回転させる（目標角、パワー、true or false）
//3つ目の引数はtrueなら目標角まで回転してから次の処理を行い、falseなら終了を待たずに次の処理を行う
void tail_spin(int angle,int spin_power,bool_t blocking){
	ev3_motor_rotate(TAIL_PORT,angle,spin_power,blocking);
}

//モータの回転角をリセットする
void reset_tail_counts(){
	ev3_motor_reset_counts(TAIL_PORT);
}

