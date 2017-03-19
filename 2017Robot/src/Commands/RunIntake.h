#ifndef RunIntake_H
#define RunIntake_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class RunIntake: public Command {
private:
	double const speed = 0.8;
public:
	RunIntake();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

};

#endif
