//��ҁF��n��
//���t�F20180926

#ifndef ACOT_RUN_STYLE_H_
#define ACOT_RUN_STYLE_H_

#define RIGHT_EDGE 1
#define LEFT_EDGE 0
//turn_run()�̃p���[
#define TURN_POWER 10
//turn_run()�̔��ˌ���臒l
#define TURN_LIGHT 5

//���C���g���[�X���s���i�E�G�b�W�����G�b�W���A�i�ރp���[�AP�W���AI�W���AD�W���j
void trace_run(int edge,char forward,double Kp,double Ki,double Kd);
//�Œ�̃p���[�ő��s����i�i�ރp���[�j
void NB_fixed_run(int forward);
//�K�����낵�O��̃��C���g���[�X
void NB_trace_run();
//���̏�ō������ɔ���]����
//���Ӂ��K�����낵�O��
void turn_run();
//���E�ԗւ��~�߂�
void twin_wheel_stop();
void twin_wheel_stop_float();

#endif
