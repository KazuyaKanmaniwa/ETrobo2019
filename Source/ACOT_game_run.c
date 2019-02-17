//作者：上馬庭
//日付：20180925

#include "ACOT_game_run.h"
#include "ACOT_lookup.h"
#include "ACOT_seesaw.h"
#include "ACOT_garage.h"
#include "ACOT_debug.h"
#include "ACOT_ET_2018.h"
#include "ev3api.h"

int game_section = 0;

void game_run(int game_mode){
	if(game_mode==GAME_LOOKUP){
		switch (game_section)
		{
		case IN:
			lookup_in();
			break;
		case GAME:
			lookup();
			break;
		case OUT:
			lookup_out();
			break;
		case FINISH:
			//ガレージイン
			garage_in();
			break;
		default:
			change_et_section();
		}
	}else if(game_mode==GAME_SEESAW){
		switch (game_section)
		{
		case IN:
			seesaw_in();
			break;
		case GAME:
			seesaw();
			break;
		case OUT:
			seesaw_out();
			break;
		default:
			change_et_section();
		}
	}
}

void change_game_section() {
	game_section++;
}

