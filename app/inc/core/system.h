#ifndef SYSTEM_H
#define SYSTEM_H

#include "common-defines.h"
#define CPU_FREQ	(84000000)
#define SYSTICK_FEQ	(1000)

void system_setup(void);
uint64_t system_get_ticks(void);
#endif // SYSTEM_H
