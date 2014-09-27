#include "Delay.h"

// For testing purposes:
#include "SmartDashboard/SmartDashboard.h"

Delay::Delay(double delayTime)
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
	
	// For testing purposes:
	SmartDashboard::PutNumber("Delay Timer", mTimer.Get());
}

void Delay::Interrupted()
{
	mTimer.Stop();
	mTimer.Reset();
	
	// For testing purposes:
	SmartDashboard::PutNumber("Delay Timer", mTimer.Get());
}
