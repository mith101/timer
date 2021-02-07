#ifndef _MITH_CTIMER_
#define _MITH_CTIMER_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define NUMBER_OF_TIMERS 10u

void mith_timer_start(const uint32_t id);
void mith_timer_stop(const uint32_t id);
uint64_t mith_timer_get_elapsed(const uint32_t id);

#ifdef __cplusplus
}
#endif

#endif // _MITH_CTIMER_
