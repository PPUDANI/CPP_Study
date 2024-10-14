#pragma once
#include <chrono>

class Timer
{
public:

    static Timer* Getinstance()
    {
        if (Instance == nullptr)
        {
            Instance = new Timer();
        }
        return Instance;
    }

    inline void StartTimer()
    {
        PrevTime = std::chrono::high_resolution_clock::now();
    }

    double TimeCheck();
    std::chrono::high_resolution_clock::time_point PrevTime;

    Timer();
    ~Timer();

private:
    static Timer* Instance;
};