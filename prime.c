#include <math.h>
#include <sys/time.h>
#include <stdio.h>

#define NUM_VALUES (10000001)
#define LAST       (NUM_VALUES-1)

int primes[NUM_VALUES];

int main()
{
    struct timeval start, stop;
    double start_ms, stop_ms, duration;
    int p, i, is_prime;

    gettimeofday(&start, NULL);

    for (p = 2; p <= LAST; ++p) {
        is_prime = 1;

        for (i = 2; i <= sqrt(LAST); ++i) {
            if (p % i == 0 && p != i) {
                is_prime = 0;
                break;
            }
        }

        primes[p] = is_prime;
    }

    gettimeofday(&stop, NULL);
    start_ms = ((double) start.tv_sec)  * 1e3
             + ((double) start.tv_usec) / 1e3;
    stop_ms  = ((double) stop.tv_sec)   * 1e3
             + ((double) stop.tv_usec)  / 1e3;
    duration = stop_ms - start_ms;

    printf("%fms\n", duration);

    /*
    for (i = 2; i <= LAST; ++i) {
        if (primes[i] == 1) {
            printf("%d\n", i);
        }
    }
    */

    return 0;
}

