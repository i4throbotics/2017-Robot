#ifndef Climber_H
#define Climber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class Climber: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> Motor1;
	std::shared_ptr<SpeedController> Motor2;

public:
	Climber();
	void InitDefaultCommand();
	void setSpeed(double speed);

};

#endif
