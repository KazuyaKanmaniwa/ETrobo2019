#include "ACOT_ET_2018.h"
#include "ACOT_calibration.h"
#include "ACOT_start.h"
#include "ACOT_speed_run.h"
#include "ACOT_game_run.h"
#include "ACOT_debug.h"

int et_section_count=0;

void et_2018(){
	all_init();
	calibration();
	while(1){
		switch(et_section_count)
		{
		case ET_START:
			couse_start();
			break;
		case ET_SPEED:
			speed_run(RIGHT_COURSE);
			break;
		case ET_GAME:
			game_run(GAME_LOOKUP);
			break;
		default:
			debug_fanfare();
			tslp_tsk(30000);
			break;
		}

		tslp_tsk(4);
	}
}

void change_et_section(){
	et_section_count++;
}
