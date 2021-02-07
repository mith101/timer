#include <mith/CTimer.h>

#include <doctest/doctest.h>
#include <iostream>

TEST_CASE("CTimer")
{
    // initial elapsed time equals 0:
    REQUIRE_EQ(mith_timer_get_elapsed(0), 0);
    REQUIRE_EQ(mith_timer_get_elapsed(1), 0);

    // sarting the timer:
    mith_timer_start(1);
    mith_timer_start(0);

    // stopping the timer stores the duration since the last call to start:
    mith_timer_stop(0);
    auto t1 = mith_timer_get_elapsed(0);
    CHECK_GT(t1, 0);

    // timer can be stopped multiple times:
    mith_timer_stop(0);
    auto t2 = mith_timer_get_elapsed(0);
    CHECK_GT(t2, t1);

    // timers with different IDs run independently:
    mith_timer_stop(1);
    CHECK_GT(mith_timer_get_elapsed(1), t2);
}
