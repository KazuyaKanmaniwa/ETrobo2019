//作者：上馬庭
//日付：20180921

#include "ACOT_PID_control.h"
#include "ACOT_debug.h"
#include "ev3api.h"

//比例係数
double PID_Kp;
//積分係数
double PID_Ki;
//微分係数
double PID_Kd;

//目標値との差分
double p_error;
//蓄積された差分
double i_error;
//直前の誤差との差分
double d_error;
//前回の目標値との誤差
double preview_error;

//目標値
double PID_middle_light;

//最初の積分計算のためのフラグ
int is_first_call=1;

//PIDの係数の初期化（P係数、I係数、D係数）
void PID_init(double Kp,double Ki,double Kd){
	PID_Kp=Kp;
	PID_Ki=Ki;
	PID_Kd=Kd;
}

//目標値設定
void set_PID_middle_light(int middle_light){
	PID_middle_light=middle_light;
}

//PID制御（反射光）　返り値：制御値
int PID_control(int refrect_light){
	double error=PID_middle_light-refrect_light;
	if(is_first_call){
		is_first_call=0;
		d_error=error;
		preview_error=error;
	}
	else{
		d_error=error-preview_error;
		preview_error=error;
	}
	p_error=error;
	i_error+=error;

	return PID_Kp*p_error+PID_Ki*i_error+PID_Kd*d_error;
}


double get_middle_light() {
	return PID_middle_light;
}
		
