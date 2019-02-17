//作者：上馬庭
//日付：20180921

#include "ACOT_debug.h"
#include "ev3api.h"
#include<stdio.h>
#include<stdlib.h>

//ディスプレイの行座標を設定
int disp_line = DISP_HEAD_LINE;
FILE *log_file;

//スクロールするディスプレイログ（文字列）
//下に書き出される
void debug_disp_write_scroll(const char *str){
	if (disp_line <= DISP_BOTTOM_LINE) {
		ev3_lcd_draw_string(str, DISP_HEAD_COLUMN, disp_line);
		disp_line += DISP_NEWLINE;
	}
	else {
		int delet_line = DISP_HEAD_LINE;
		while (delet_line <= DISP_BOTTOM_LINE) {
			ev3_lcd_draw_string("                            ", DISP_HEAD_COLUMN, delet_line);
			//空白28
			delet_line += DISP_NEWLINE;
		}
		disp_line = DISP_HEAD_LINE;
		debug_disp_write_scroll(str);
	}
}

//書き出しファイルを開く（ファイル名）
//注意＊ファイル名は拡張子まで書くこと
void debug_file_open(const char *file_name){
	log_file=fopen(file_name,"w");
}

//数値をファイルに書き出す（データ）
void debug_file_write(float data){
	if(log_file!=NULL){
		fprintf(log_file,"%f\n",data);
	}
}

//書き出しファイルを閉じる
void debug_file_close(){
	if(log_file!=NULL){
		fclose(log_file);
	}
}

//音を鳴らす
void debug_tone(){
	ev3_speaker_play_tone(NOTE_F4,TONE_TIME);
}

//int型をchar型に変換する（数値）
char* debug_itoc(int data){
	static char trans_array[10];
	sprintf(trans_array, "%d", data);
	return trans_array;
}

//固定位置に書くディスプレイログ（データの名前、データ、行座標）
void debug_disp_write_fixed(char *data_name, int data, int fixed_line) {
	ev3_lcd_draw_string("     ", DISP_MIDDLE_COLUMN, fixed_line);
	ev3_lcd_draw_string(data_name, DISP_HEAD_COLUMN, fixed_line);
	char *trans_data = debug_itoc(data);
	ev3_lcd_draw_string(trans_data, DISP_MIDDLE_COLUMN, fixed_line);
}

//電圧を表示する
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
