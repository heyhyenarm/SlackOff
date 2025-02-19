#include "PreCompiledHeader.h"
#include "Timer.h"

Timer::Timer(float targetTime)
	: targetTime(targetTime)
{
}

void Timer::Update(float deltaTime)
{
	if (isTimerPause)
	{
		return;
	}
	elapsedTime += deltaTime;
}

void Timer::Reset()
{
	elapsedTime = 0.0f;
}

bool Timer::TogglePause()
{
	return isTimerPause = !isTimerPause;
}
