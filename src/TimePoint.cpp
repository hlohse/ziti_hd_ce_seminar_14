#include "TimePoint.h"
    
TimePoint::TimePoint(const double time_point_s)
:   time_point_s_(time_point_s)
{
}

double TimePoint::S() const
{
    return time_point_s_;
}

double TimePoint::MS() const
{
    return time_point_s_ * 1e3;
}

double TimePoint::US() const
{
    return time_point_s_ * 1e6;
}

double TimePoint::NS() const
{
    return time_point_s_ * 1e9;
}

