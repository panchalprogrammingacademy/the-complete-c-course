// define delay.h if not defined already
#ifndef _DELAY_H
#define _DELAY_H

// required for clock
#include <time.h>

// define the delay function
void busy_wait(int millis){
    // get the current system time in millis
    clock_t start = clock();
    // stores the time to pause
    long end = millis * (CLOCKS_PER_SEC / 1000);
    // busy-wait till reach to the end
    while (clock() < start + end) { }
}

#endif