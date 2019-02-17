//��ҁF��n��
//���t�F20180921

#include "ACOT_debug.h"
#include "ev3api.h"
#include<stdio.h>
#include<stdlib.h>

//�f�B�X�v���C�̍s���W��ݒ�
int disp_line = DISP_HEAD_LINE;
FILE *log_file;

//�X�N���[������f�B�X�v���C���O�i������j
//���ɏ����o�����
void debug_disp_write_scroll(const char *str){
	if (disp_line <= DISP_BOTTOM_LINE) {
		ev3_lcd_draw_string(str, DISP_HEAD_COLUMN, disp_line);
		disp_line += DISP_NEWLINE;
	}
	else {
		int delet_line = DISP_HEAD_LINE;
		while (delet_line <= DISP_BOTTOM_LINE) {
			ev3_lcd_draw_string("                            ", DISP_HEAD_COLUMN, delet_line);
			//��28
			delet_line += DISP_NEWLINE;
		}
		disp_line = DISP_HEAD_LINE;
		debug_disp_write_scroll(str);
	}
}

//�����o���t�@�C�����J���i�t�@�C�����j
//���Ӂ��t�@�C�����͊g���q�܂ŏ�������
void debug_file_open(const char *file_name){
	log_file=fopen(file_name,"w");
}

//���l���t�@�C���ɏ����o���i�f�[�^�j
void debug_file_write(float data){
	if(log_file!=NULL){
		fprintf(log_file,"%f\n",data);
	}
}

//�����o���t�@�C�������
void debug_file_close(){
	if(log_file!=NULL){
		fclose(log_file);
	}
}

//����炷
void debug_tone(){
	ev3_speaker_play_tone(NOTE_F4,TONE_TIME);
}

//int�^��char�^�ɕϊ�����i���l�j
char* debug_itoc(int data){
	static char trans_array[10];
	sprintf(trans_array, "%d", data);
	return trans_array;
}

//�Œ�ʒu�ɏ����f�B�X�v���C���O�i�f�[�^�̖��O�A�f�[�^�A�s���W�j
void debug_disp_write_fixed(char *data_name, int data, int fixed_line) {
	ev3_lcd_draw_string("     ", DISP_MIDDLE_COLUMN, fixed_line);
	ev3_lcd_draw_string(data_name, DISP_HEAD_COLUMN, fixed_line);
	char *trans_data = debug_itoc(data);
	ev3_lcd_draw_string(trans_data, DISP_MIDDLE_COLUMN, fixed_line);
}

//�d����\������
void debug_check_volt() {
	debug_disp_write_fixed("Volt", ev3_battery_voltage_mV(),DISP_BOTTOM_LINE+10);
}

void debug_fanfare() {
	ev3_speaker_play_tone(NOTE_A4, 2*TONE_TIME);
	tslp_tsk(150);
	ev3_speaker_play_tone(NOTE_A4, 2*TONE_TIME);
	tslp_tsk(150);
	ev3_speaker_play_tone(NOTE_A4, 2*TONE_TIME);
	tslp_tsk(150);
	ev3_speaker_play_tone(NOTE_A4, 5*TONE_TIME);
	tslp_tsk(500);
	ev3_speaker_play_tone(NOTE_F4, 5*TONE_TIME);
	tslp_tsk(500);
	ev3_speaker_play_tone(NOTE_G4, 5*TONE_TIME);
	tslp_tsk(500);
	ev3_speaker_play_tone(NOTE_A4, 2*TONE_TIME);
	tslp_tsk(300);
	ev3_speaker_play_tone(NOTE_G4, 2*TONE_TIME);
	tslp_tsk(200);
	ev3_speaker_play_tone(NOTE_A4, 4*TONE_TIME);
	tslp_tsk(500);
}
