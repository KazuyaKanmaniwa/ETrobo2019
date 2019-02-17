//��ҁF��n��
//���t�F20180922

#include "ACOT_wheel.h"
#include "ACOT_debug.h"
#include "ev3api.h"

//���E�ԗփ��[�^�̏�����
void twin_wheel_init(){
	ev3_motor_config(RIGHT_WHEEL_PORT,LARGE_MOTOR);
	ev3_motor_config(LEFT_WHEEL_PORT, LARGE_MOTOR);
	reset_wheel_counts(RIGHT_WHEEL);
	reset_wheel_counts(LEFT_WHEEL);
}

//�ԗւ���]������i�p���[�A���E�j
void wheel_run(int power,int LorR){
	if (power < -100) {
		power = -100;
	}
	else if (power > 100) {
		power = 100;
	}

	if(LorR==RIGHT_WHEEL){
		ev3_motor_set_power(RIGHT_WHEEL_PORT,power);
	}else if(LorR==LEFT_WHEEL){
		ev3_motor_set_power(LEFT_WHEEL_PORT,power);
	}
}

//�ԗւ��~�߂�i���E�j
void wheel_stop(int LorR,int BorF){
	if(BorF==BRAKE){
		if(LorR==RIGHT_WHEEL){
			ev3_motor_stop(RIGHT_WHEEL_PORT,true);
		}else if(LorR==LEFT_WHEEL){
			ev3_motor_stop(LEFT_WHEEL_PORT,true);
		}
	}else if(BorF==FLOAT){
		if(LorR==RIGHT_WHEEL){
			ev3_motor_stop(RIGHT_WHEEL_PORT,false);
		}else if(LorR==LEFT_WHEEL){
			ev3_motor_stop(LEFT_WHEEL_PORT,false);
		}
	}
}

//�ԗւ̉�]�p�����Z�b�g����i���E�j�@
void reset_wheel_counts(int LorR){
	if(LorR==RIGHT_WHEEL){
		ev3_motor_reset_counts(RIGHT_WHEEL_PORT);
	}else if(LorR==LEFT_WHEEL){
		ev3_motor_reset_counts(LEFT_WHEEL_PORT);
	}
}

//�ԗւ̉�]�p���擾����i���E�j�@�Ԃ�l�F�ԗւ̉�]�p
int32_t get_wheel_counts(int LorR){
	int wheel_counts=0;
	if(LorR==RIGHT_WHEEL){
		wheel_counts=ev3_motor_get_counts(RIGHT_WHEEL_PORT);
	}else if(LorR==LEFT_WHEEL){
		wheel_counts=ev3_motor_get_counts(LEFT_WHEEL_PORT);
	}
	return wheel_counts;
}
