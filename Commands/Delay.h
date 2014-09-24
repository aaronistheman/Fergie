#ifndef DELAY_H
#define DELAY_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class Delay: public Command {
public:
	Delay(double delayTime);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
private:
	double 		mDelayTime;
	Timer 		mTimer;
};

#endif
