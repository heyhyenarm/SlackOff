#pragma once

#include "Clock.h"

class Timer : public Clock
{
public:
	Timer(float targetTime);
	~Timer() = default;

private:
	inline float IsTimeOut() { return (float)Clock::GetDurationSeconds() >= targetTime; }

private:
	float targetTime = 0;
};

Timer::Timer(float targetTime)
	: Clock(), targetTime(targetTime)
{

}

