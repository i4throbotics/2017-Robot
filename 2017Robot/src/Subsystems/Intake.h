#ifndef Intake_H
#define Intake_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class Intake: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> Motor;

public:
	Intake();
	void InitDefaultCommand();
	void setSpeed(double speed);

};

#endif
