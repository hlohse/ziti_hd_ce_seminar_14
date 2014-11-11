#ifndef ZITI_HD_CE_SEMINAR_14_POINTER_CHASING_TIME_POINT_H
#define ZITI_HD_CE_SEMINAR_14_POINTER_CHASING_TIME_POINT_H

class TimePoint {
public:
    TimePoint(const double time_point_s);

    double S() const;
    double MS() const;
    double US() const;
    double NS() const;

private:
    double time_point_s_;
};

#endif // ZITI_HD_CE_SEMINAR_14_POINTER_CHASING_TIME_POINT_H

