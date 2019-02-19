//��ҁF��n��
//���t�F20180926

#include "ACOT_run_style.h"
#include "ACOT_balancer.h"
#include "ACOT_PID_control.h"
#include "ACOT_light_sensor.h"
#include "ACOT_wheel.h"
#include "ACOT_debug.h"
#include "ACOT_distance_estimation.h"
#include "ev3api.h"

//���C���g���[�X���s���i�E�G�b�W�����G�b�W���A�i�ރp���[�AP�W���AI�W���AD�W���j
void trace_run(int edge,char forward,double Kp,double Ki,double Kd){
	int *power;
	PID_init(Kp,Ki,Kd);
	int32_t wheel_counts_R = get_wheel_counts(RIGHT_WHEEL);
	int32_t wheel_counts_L = get_wheel_counts(LEFT_WHEEL);
	int turn=PID_control(get_cal_reflected_light());
	power = acot_balance_control(forward, turn, wheel_counts_R, wheel_counts_L);

	if (edge == LEFT_EDGE) {
		int ahead = power[0];
		power[0] = power[1];
		power[1] = ahead;
	}

	if (power[RIGHT_WHEEL] == 0) {
		wheel_stop(RIGHT_WHEEL,BRAKE);
	}
	else {
		wheel_run(power[RIGHT_WHEEL], RIGHT_WHEEL);
	}
	if (power[LEFT_WHEEL] == 0) {
		wheel_stop(LEFT_WHEEL,BRAKE);
	}
	else {
		wheel_run(power[LEFT_WHEEL], LEFT_WHEEL);
	}
}

//�Œ�̃p���[�ő��s����i�i�ރp���[�j
//���Ӂ��K�����낵�O��
void NB_fixed_run(int forward) {
	wheel_run(forward, RIGHT_WHEEL);
	wheel_run(forward, LEFT_WHEEL);
}

//���̏�ō������ɔ���]����
//���Ӂ��K�����낵�O��
void turn_run() {
	wheel_run(TURN_POWER, RIGHT_WHEEL);
	wheel_run(-1 * TURN_POWER, LEFT_WHEEL);
	tslp_tsk(2900);
	twin_wheel_stop();
}

//���E�ԗւ��~�߂遦�O���b�v�~��
void twin_wheel_stop() {
	wheel_stop(RIGHT_WHEEL,BRAKE);
	wheel_stop(LEFT_WHEEL,BRAKE);
}

//���E�ԗւ��~�߂遦���炩�Ɏ~�߂�
void twin_wheel_stop_float(){
	wheel_stop(RIGHT_WHEEL,FLOAT);
	wheel_stop(LEFT_WHEEL,FLOAT);
}

//�o�����T�[���g��Ȃ����s
void NB_trace_run() {
	PID_init(0.5, 0, 0);
	int power = 10;
	int turn = PID_control(get_reflected_light());
	wheel_run(power + turn, RIGHT_WHEEL);
	wheel_run(power - turn, LEFT_WHEEL);
}