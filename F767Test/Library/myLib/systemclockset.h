#include <stdint.h>
#ifndef __SYSTEM_CLOCK_SET_H__
#define __SYSTEM_CLOCK_SET_H__

void SystemCache_Enable(void);
void SystemClock_Config(uint32_t pllm, uint32_t plln, uint32_t pllp, uint32_t pllq);

#endif

