#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class Shooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> Motor;
public:
	Shooter();
	void InitDefaultCommand();
	void setSpeed(double speed);
	double getVolt();

};

#endif
