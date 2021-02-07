#ifndef _MITH_TIMER_
#define _MITH_TIMER_

#include <chrono>
#include <cstdint>

namespace mith {

template <int ID>
class Timer
{
  public:
    using Clock = std::chrono::high_resolution_clock;

    Timer() = delete;

    static void start();
    static void stop();
    static int64_t getElapsed();

  private:
    static Clock::time_point t_start;
    static Clock::duration elapsed;
};

template <int ID>
typename Timer<ID>::Clock::time_point Timer<ID>::t_start;

template <int ID>
typename Timer<ID>::Clock::duration Timer<ID>::elapsed;

template <int ID>
void Timer<ID>::start()
{
    t_start = Clock::now();
}

template <int ID>
void Timer<ID>::stop()
{
    elapsed = Clock::now() - t_start;
}

template <int ID>
int64_t Timer<ID>::getElapsed()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed)
        .count();
}

} // namespace mith

#endif // _MITH_TIMER_
