#ifndef _TIMER_H
#define _TIMER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Time
{
public:
	Time();
	float GetTimeStep() const;
	void Start();
private:
	float mTimeStep;
	float mCurrentTime;
	float mLastTime;
};

#endif