#include "Timer.h"

Time::Time()
	: mTimeStep    {}
	, mCurrentTime {}
	, mLastTime    {}
{

}

void Time::Start()
{
	mCurrentTime = static_cast<float>(glfwGetTime());
	mTimeStep = mCurrentTime - mLastTime;
	mLastTime = mCurrentTime;
}

float Time::GetTimeStep()
{
	return mTimeStep;
}