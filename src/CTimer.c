#include <mith/CTimer.h>
// ...
#include <assert.h>
#include <stdio.h>
#include <time.h>

struct timespec t_start[NUMBER_OF_TIMERS];
struct timespec t_stop[NUMBER_OF_TIMERS];

void mith_timer_start(const uint32_t id)
{
    assert(id < NUMBER_OF_TIMERS);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_start[id]);
}

void mith_timer_stop(const uint32_t id)
{
    assert(id < NUMBER_OF_TIMERS);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_stop[id]);
}

uint64_t mith_timer_get_elapsed(const uint32_t id)
{
    assert(id < NUMBER_OF_TIMERS);
    return 1e9 * (t_stop[id].tv_sec - t_start[id].tv_sec) +
           (t_stop[id].tv_nsec - t_start[id].tv_nsec);
}
