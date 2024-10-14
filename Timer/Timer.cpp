#include "Timer.h"
#include <iostream>

Timer* Timer::Instance = nullptr;

Timer::Timer() 
{
}

Timer::~Timer()
{
    if (nullptr != Instance)
    {
        delete Instance;
    }
}

double Timer::TimeCheck() 
{
    auto CurTime = std::chrono::high_resolution_clock::now();
    auto sec = std::chrono::duration<double>(CurTime - PrevTime);
    PrevTime = CurTime;
    return sec.count();
}
