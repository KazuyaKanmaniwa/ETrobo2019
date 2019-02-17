//��ҁF��n��
//���t�F20180925

#ifndef ACOT_DEBUG_H_
#define ACOT_DEBUG_H_

#include<stdio.h>
#include "ev3api.h"

//����炷���ԁi�����j
#define TONE_TIME 100
//�s���W�̐擪
#define DISP_HEAD_LINE 10
//�s���W�̍Ō�
#define DISP_BOTTOM_LINE 110
//����W�̐擪
#define DISP_HEAD_COLUMN 10
//����W�̐^��
#define DISP_MIDDLE_COLUMN 110
//�X�N���[���̎����W
#define DISP_NEWLINE 10

//�X�N���[������f�B�X�v���C���O�i������j
//���ɏ����o�����
void debug_disp_write_scroll(const char *str);
//�����o���t�@�C�����J���i�t�@�C�����j
//���Ӂ��t�@�C�����͊g���q�܂ŏ�������
void debug_file_open(const char *file_name);
//���l���t�@�C���ɏ����o���i�f�[�^�j
void debug_file_write(float data);
//�����o���t�@�C�������
void debug_file_close();
//����炷
void debug_tone();
//�Œ�ʒu�ɏ����f�B�X�v���C���O�i�f�[�^�̖��O�A�f�[�^�A����W�j
void debug_disp_write_fixed(char *data_name, int data, int fixed_line);
//int�^��char�^�ɕϊ�����i���l�j
char* debug_itoc(int data);
//�d����\������
void debug_check_volt();
























//�����̃t�@���t�@�[��
void debug_fanfare();

#endif

