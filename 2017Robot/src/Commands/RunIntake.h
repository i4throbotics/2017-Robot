#ifndef RunIntake_H
#define RunIntake_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class RunIntake: public Command {

public:
	RunIntake();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

};

#endif
