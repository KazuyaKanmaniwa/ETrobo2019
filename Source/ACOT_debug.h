//作者：上馬庭
//日付：20180925

#ifndef ACOT_DEBUG_H_
#define ACOT_DEBUG_H_

#include<stdio.h>
#include "ev3api.h"

//音を鳴らす時間（ｍｓ）
#define TONE_TIME 100
//行座標の先頭
#define DISP_HEAD_LINE 10
//行座標の最後
#define DISP_BOTTOM_LINE 110
//列座標の先頭
#define DISP_HEAD_COLUMN 10
//列座標の真ん中
#define DISP_MIDDLE_COLUMN 110
//スクロールの次座標
#define DISP_NEWLINE 10

//スクロールするディスプレイログ（文字列）
//下に書き出される
void debug_disp_write_scroll(const char *str);
//書き出しファイルを開く（ファイル名）
//注意＊ファイル名は拡張子まで書くこと
void debug_file_open(const char *file_name);
//数値をファイルに書き出す（データ）
void debug_file_write(float data);
//書き出しファイルを閉じる
void debug_file_close();
//音を鳴らす
void debug_tone();
//固定位置に書くディスプレイログ（データの名前、データ、列座標）
void debug_disp_write_fixed(char *data_name, int data, int fixed_line);
//int型をchar型に変換する（数値）
char* debug_itoc(int data);
//電圧を表示する
void debug_check_volt();
























//勝利のファンファーレ
void debug_fanfare();

#endif

