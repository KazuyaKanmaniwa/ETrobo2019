//作者：上馬庭
//日付：20180924

#include "ACOT_calibration.h"
#include "ACOT_light_sensor.h"
#include "ACOT_wheel.h"
#include "ACOT_run_style.h"
#include "ACOT_balancer.h"
#include "ACOT_button.h"
#include "ACOT_tail_control.h"
#include "ACOT_bluetooth.h"
#include "ACOT_ultrasonic_sensor.h"
#include "ACOT_PID_control.h"
#include "ACOT_debug.h"

//すべての初期化
//プログラムの一番最初に持ってくる
void all_init(){
	light_sensor_init();
	twin_wheel_init();
	twin_wheel_stop();
	acot_balancer_init();
	button_init();
	tail_control_init();
	bluetooth_init();
	ultrasonic_sensor_init();
	debug_check_volt();
}

//キャリブレーション設定
//白黒灰の値をとってPIDの目標値を設定する
void calibration(){
	debug_tone();
	debug_disp_write_fixed("Calibration", 0, 10);

	tslp_tsk(3000);

	debug_disp_write_fixed("Redy       ", 0, 10);
	button_wait_push();
	debug_tone();
	int black = get_reflected_light();
	debug_disp_write_fixed("black", black, 10);
	button_wait_push();
	debug_tone();
	int white = get_reflected_light();
	debug_disp_write_fixed("white", white, 20);
	button_wait_push();
	debug_tone();
	int midd_point = ((black + white) / 2)-black;
	set_PID_middle_light(midd_point);
}
