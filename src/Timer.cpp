#include "Timer.h"

TimePoint Timer::Resolution()
{
    static const double resolution_s =
        (double) std::chrono::high_resolution_clock::period::num /
        (double) std::chrono::high_resolution_clock::period::den;
    return TimePoint(resolution_s);
}

void Timer::Start()
{
    start_ = clock_.now();
}

void Timer::Stop()
{
    stop_ = clock_.now();
}

TimePoint Timer::Duration() const
{
    return TimePoint((stop_ - start_).count());
}

