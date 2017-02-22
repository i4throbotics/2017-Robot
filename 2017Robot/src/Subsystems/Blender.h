#ifndef Blender_H
#define Blender_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class Blender: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> blenderMotor;

public:
	Blender();
	void InitDefaultCommand();
	void setSpeed(double speed);

};

#endif
