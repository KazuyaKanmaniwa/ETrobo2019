//��ҁF��n��
//���t�F20180922

#ifndef ACOT_SPEED_RUN_H_
#define ACOT_SPEED_RUN_H_

#include "ev3api.h"

//��Ԑ�
#define SPEED_SECTION 8
//�p�����[�^�̐�
#define PARAMS 4
//�p���[�̔z��ꏊ
#define POWER 0
//P�W���̔z��ꏊ
#define KP 1
//I�W���̔z��ꏊ
#define KI 2
//D�W���̔z��ꏊ
#define KD 3
//�R�[�X�I���i��Ԑ���p�j
#define COURSE 2

#define RIGHT_COURSE 0
#define LEFT_COURSE 1

//�X�s�[�h�R�[�X�𑖍s����iR��L�R�[�X�j
void speed_run(int course);
#endif

