#ifndef ShooterRamp_H
#define ShooterRamp_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class ShooterRamp: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> Ramp;
public:
	ShooterRamp();
	void InitDefaultCommand();
	double getEncoder();
	void setRampSpeed(double speed);
	void resetEncoder();
	void brake();
	void unbrake();
};

#endif
