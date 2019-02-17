//作者：上馬庭
//日付：20180923

#ifndef ACOT_GAME_RUN_H_
#define ACOT_GAME_RUN_H_

#include "ev3api.h"

#define GAME_SECTION 4
#define GAME_LOOKUP 0
#define GAME_SEESAW 1
#define IN 0
#define GAME 1
#define OUT 2
#define FINISH 3

void game_run(int game_mode);
void change_game_section();

#endif
