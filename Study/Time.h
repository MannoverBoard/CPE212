#ifndef TIME_H
#define TIME_H

class Time
{
    public:

    // Constructors:
    Time();     // Default constructor sets time to 0:0:0

    Time(int initHrs, int initMins, int initSecs );
    // Constructs time using incoming parameters

    //Transformers:
    void Set(int hours, int minutes, int seconds );

    void Increment();


    // Observers:
    void Write() const;

};
#endif