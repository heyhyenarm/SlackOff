#pragma once

#include <iostream>
#include <time.h>

//���� �ð� ������ ���� Clock. 
class Clock
{
public:
	explicit Clock();
	explicit Clock(int finish);
	~Clock() = default;

	inline void StartClock() { start = clock(); };
	inline void StopClock() { finish = clock(); };
	inline double GetDurationSeconds() { return duration + (double)(finish - start) / CLOCKS_PER_SEC; };
	inline double GetDurationMSeconds() { return duration + (double)(finish - start); };
	
	//Clock �Ͻ�����. 
	void PauseClock();
	//Clock �̾ �����ϱ�. 
	void ReStartClock();

private:

	clock_t start;
	clock_t finish;

	double duration = 0;
};

Clock::Clock()
	: start(0), finish(0)
{
}

void Clock::PauseClock()
{
	duration = (double)(clock() - start) / CLOCKS_PER_SEC;
	start = 0;
}

void Clock::ReStartClock()
{
	start = clock();
}
