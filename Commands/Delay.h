#ifndef DELAY_H
#define DELAY_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class Delay: public Command {
public:
	Delay(int delayTime);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
private:
	int 		mDelayTime;
	Timer 		mTimer;
};

#endif
