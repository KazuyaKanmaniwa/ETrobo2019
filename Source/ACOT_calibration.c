//��ҁF��n��
//���t�F20180924

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

//���ׂĂ̏�����
//�v���O�����̈�ԍŏ��Ɏ����Ă���
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

//�L�����u���[�V�����ݒ�
//�����D�̒l���Ƃ���PID�̖ڕW�l��ݒ肷��
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
