//��ҁF��n��
//���t�F20180922

#include "ACOT_tail.h"
#include "ev3api.h"
#include "ACOT_wheel.h"

//�K�����[�^������
void tail_init(){
	ev3_motor_config(TAIL_PORT,LARGE_MOTOR);
}

//�K������]������i�ڕW�p�A�p���[�Atrue or false�j
//3�ڂ̈�����true�Ȃ�ڕW�p�܂ŉ�]���Ă��玟�̏������s���Afalse�Ȃ�I����҂����Ɏ��̏������s��
void tail_spin(int angle,int spin_power,bool_t blocking){
	ev3_motor_rotate(TAIL_PORT,angle,spin_power,blocking);
}

//���[�^�̉�]�p�����Z�b�g����
void reset_tail_counts(){
	ev3_motor_reset_counts(TAIL_PORT);
}

