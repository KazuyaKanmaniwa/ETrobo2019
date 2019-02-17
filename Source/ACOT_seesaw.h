//作者：上馬庭
//日付：20180923

#ifndef ACOT_SEESAW_H_
#define ACOT_SEESAW_H_

#include "ev3api.h"

#define INVATION_LOW_POWER 40
#define INVATION_HIGH_POWER 100
#define INVATION_GYRO_RATE 40
#define SEESAW_SECTION 3
int seesaw_section_count;

void seesaw_in();
void seesaw();
void seesaw_out();

#endif
