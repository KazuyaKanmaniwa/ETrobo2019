//作者：上馬庭
//日付：20180926

#ifndef ACOT_LOOKUP_H_
#define ACOT_LOOKUP_H_

#include "ev3api.h"

#define LOOKUP_SONIC_MIN 5
#define LOOKUP_SONIC_MAX 15
#define LOOKUP_WHEEL_POWER 10
#define LOOKUP_COUNT_LIMIT 3
#define LOOKUP_LEAN_RUN_DISTANCE 35
#define LOOKUP_LEAN_POWER -5
#define LOOKUP_LEAN_ANGLE 20

void lookup_in();
void lookup();
void lookup_out();

#endif

