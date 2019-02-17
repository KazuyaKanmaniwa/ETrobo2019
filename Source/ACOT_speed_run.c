//作者：上馬庭　数値編集：野島
//日付：20180923

#include "ACOT_speed_run.h"
#include "ACOT_run_style.h"
#include "ACOT_distance_estimation.h"
#include "ACOT_tail_control.h"
#include "ACOT_debug.h"
#include "ACOT_ET_2018.h"
#include "ev3api.h"

//Rコースの区間パラメータ｛パワー、P係数、I係数、D係数｝
double right_section_params[SPEED_SECTION][PARAMS]={{100,0.45,0,8.3},//直線
													{100,0.4,0,7.5},//曲線
													{100,0.45,0,8.3},//直線
													{100,0.4,0,7.5},//曲線
													{100,0.45,0,8.3},//直線
													{100,0.4,0,7.5},//曲線
													{100,0.4,0,8.2},//直線
													{100,0.4,0,7.5}	};//曲線


//直線 100,0.4,0,8.2	100,0.45,0,8.3	100,0.5,0,8.5
//曲線 100,0.4,0,7.5

/*double right_section_params[SPEED_SECTION][PARAMS]={{100,0.1,0.04,10.5},//直線
													{80,0.1,0.16,16.5},//曲線
													{85,0.1,0.12,12.5},//直線
													{75,0.1,0.24,15},//曲線
													{75,0.1,0.08,10.5},//直線
													{80,0.1,0.2,7.5},//曲線
													{100,0.1,0.04,10.5},//直線
													{50,0.1,0.2,10.5}	};//曲線


*/
//Lコースの区間パラメータ｛パワー、P係数、I係数、D係数｝
double left_section_params[SPEED_SECTION][PARAMS]={	{100,0.4,0,8.2},//直線
													{100,0.37,0,7.3},//曲線
													{100,0.4,0,8.2},//直線
													{100,0.4,0,7.5},//曲線
													{100,0.4,0,8.2},//直線
													{90,0.42,0,7.5},//曲線
													{100,0.4,0,8.2},//直線
													{50,0.2,0,8} };//曲線

//各区間の距離
int section_distance[COURSE][SPEED_SECTION]={{200,180,30,140,53,125,250,0},//Rコース
											 {195,180,160,71,35,90,240,0}};//Lコース

//区間制御のためのカウント
int section_count=0;
int select_course;

//スピードコースを走行する（RかLコース）
void speed_run(int course){
	if (course == RIGHT_COURSE) {
		trace_run(LEFT_EDGE, right_section_params[section_count][POWER],
			right_section_params[section_count][KP],
			right_section_params[section_count][KI],
			right_section_params[section_count][KD]);
	}
	else {
		trace_run(LEFT_EDGE, left_section_params[section_count][POWER],
			left_section_params[section_count][KP],
			left_section_params[section_count][KI],
			left_section_params[section_count][KD]);
	}

	

	if(get_distance()>section_distance[course][section_count]){
		reset_distance();
		debug_tone();
		section_count++;
		if(section_count==SPEED_SECTION){
			//難所攻略へ
			tail_stol();
			change_et_section();
		}
	}
}

