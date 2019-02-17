//作者：上馬庭
//日付：20180926

#ifndef ACOT_RUN_STYLE_H_
#define ACOT_RUN_STYLE_H_

#define RIGHT_EDGE 1
#define LEFT_EDGE 0
//turn_run()のパワー
#define TURN_POWER 10
//turn_run()の反射光の閾値
#define TURN_LIGHT 5

//ライントレースを行う（右エッジか左エッジか、進むパワー、P係数、I係数、D係数）
void trace_run(int edge,char forward,double Kp,double Ki,double Kd);
//固定のパワーで走行する（進むパワー）
void NB_fixed_run(int forward);
//尻尾下ろし前提のライントレース
void NB_trace_run();
//その場で左方向に半回転する
//注意＊尻尾下ろし前提
void turn_run();
//左右車輪を止める
void twin_wheel_stop();
void twin_wheel_stop_float();

#endif
