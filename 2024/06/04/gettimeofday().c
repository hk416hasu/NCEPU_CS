#include <stdio.h>
#include <time.h>
#include <sys/time.h>

struct timeval {
    time_t      tv_sec;     /* seconds */
    suseconds_t tv_usec;    /* microseconds */
};

struct timezone {
    int tz_minuteswest;     /* minutes west of Greenwich */
    int tz_dsttime;         /* type of DST correction */
};

int mian() {
    struct timeval a; a.tv_sec = 0;
    struct timezone b; b.tz_dsttime = 8;  

    int start = gettimeofday(&a, &b);
    
    Sleep(5000);

    printf("%d\n", gettimeofday(&a, &b) - start);

    return 0;
}