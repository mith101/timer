#include <doctest/doctest.h>
#include <mith/Timer.h>

TEST_CASE("Timer")
{
    // initial elapsed time equals 0:
    REQUIRE_EQ(mith::Timer<0>::getElapsed(), 0);
    REQUIRE_EQ(mith::Timer<1>::getElapsed(), 0);

    // sarting the timer:
    mith::Timer<1>::start();
    mith::Timer<0>::start();

    // stopping the timer stores the duration since the last call to start:
    mith::Timer<0>::stop();
    auto t1 = mith::Timer<0>::getElapsed();
    CHECK_GT(t1, 0);

    // timer can be stopped multiple times:
    mith::Timer<0>::stop();
    auto t2 = mith::Timer<0>::getElapsed();
    CHECK_GT(t2, t1);

    // timers with different IDs run independently:
    mith::Timer<1>::stop();
    CHECK_GT(mith::Timer<1>::getElapsed(), t2);
}
