//��ҁF��n��
//���t�F20180912

#ifndef ACOT_BUTTON_H_
#define ACOT_BUTTON_H_

#include "ev3api.h"

//�{�^���̃|�[�g
#define BUTTON_PORT EV3_PORT_1

//�{�^��������
void button_init();
//�{�^�����������܂ő҂�
//���Ӂ��R�[�h�������Ŏ~�܂�
void button_wait_push();

#endif

