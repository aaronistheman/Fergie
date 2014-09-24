#include "Delay.h"

Delay::Delay(int delayTime)
: mDelayTime(delayTime)
, mTimer()
{
}

void Delay::Initialize()
{
	mTimer.Start();
}

void Delay::Execute()
{
	// Do nothing but delay
}

bool Delay::IsFinished()
{
	return mTimer.HasPeriodPassed(mDelayTime);
}

void Delay::End()
{
	mTimer.Stop();
	mTimer.Reset();
}

void Delay::Interrupted()
{
	mTimer.Stop();
	mTimer.Reset();
}
