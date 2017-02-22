#ifndef FlipChassis_H
#define FlipChassis_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class FlipChassis: public Command {

public:
	FlipChassis();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

};

#endif
