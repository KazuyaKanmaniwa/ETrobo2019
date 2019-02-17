//��ҁF��n��
//���t�F20180926

#include "ACOT_start.h"
#include "ACOT_tail_control.h"
#include "ACOT_bluetooth.h"
#include "ACOT_debug.h"
#include "ACOT_distance_estimation.h"
#include "ACOT_run_style.h"
#include "ACOT_ET_2018.h"

//�X�^�[�g������s��
void couse_start(){
	tail_stand();
	debug_tone();
	while(1){
		if(is_bluetooth_signal()){
			tail_return();
			break;
		}
	}

	while (1) {
		if (get_distance() > APPROACH_RUN) {
			reset_distance();
			break;
		}
		trace_run(LEFT_EDGE, 80, 0.3, 0, 8);
		tslp_tsk(4);
	}

	//��{���s��
	change_et_section();
}

