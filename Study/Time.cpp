#include <iostream>

#include "Time.h"

Time::Time() {
    hrs = 0;
    mins = 0;
    secs = 0;
}

Time::Time(int initHrs, int initMins, int initSecs) {
    hrs->initHrs;
    mins->initMins;
    secs->initSecs;
}

void Time::Set(int hours, int minutes, int seconds) {
    hrs->hours;
    mins->minutes;
    secs->seconds;
}

void Time::Increment() {
    secs++;
    if (secs > 59)
    {
        secs = 0;
        mins++;
        
        if (mins > 59)
        {
            mins = 0;
            hrs++

            if (hrs > 23)
                hrs = 0;
        }
    }
}

void Time::Write() const {
    if (hrs < 10)
        std::cout << '0';
    std::cout << hrs << ':';

    if (mins < 10)
        std::cout << '0';
    std::cout << mins << ':';

    if (secs < 10)
        std::cout << '0';
    std::cout << secs;
}

