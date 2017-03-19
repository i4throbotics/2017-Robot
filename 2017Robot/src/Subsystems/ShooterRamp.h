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
	std::shared_ptr<Counter> RampCounter;
	int totalCount;
	int lastCount;
public:
	ShooterRamp();
	void InitDefaultCommand();
	void setRampSpeed(double speed);
	int getCount();
};

#endif
