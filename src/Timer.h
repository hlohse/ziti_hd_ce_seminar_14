#ifndef ZITI_HD_CE_SEMINAR_14_POINTER_CHASING_TIMER_H
#define ZITI_HD_CE_SEMINAR_14_POINTER_CHASING_TIMER_H

#include "TimePoint.h"
#include <chrono>

class Timer {
public:
    static TimePoint Resolution();

    void Start();
    void Stop();

    TimePoint Duration() const;

private:
    std::chrono::high_resolution_clock             clock_;
    std::chrono::high_resolution_clock::time_point start_;
    std::chrono::high_resolution_clock::time_point stop_;
};

#endif // ZITI_HD_CE_SEMINAR_14_POINTER_CHASING_TIMER_H

