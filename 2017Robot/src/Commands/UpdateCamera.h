
#ifndef UpdateCamera_H
#define UpdateCamera_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class UpdateCamera: public Command {

public:
	UpdateCamera();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();


};


#endif
