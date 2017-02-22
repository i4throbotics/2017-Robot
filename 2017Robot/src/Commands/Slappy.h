#ifndef Slappy_H
#define Slappy_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Slappy: public Command {

public:
	Slappy();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

};

#endif
