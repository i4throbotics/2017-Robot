#ifndef Camera_H
#define Camera_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"

class Camera: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<I2C> wire;

	bool gearDetected;
	bool goalDetected;
	double angularOffset;
	double xOffset;
	double yOffset;

public:
	Camera();
	void InitDefaultCommand();
	void Update();
	double getAngularOffset() const {
		return angularOffset;
	}

	bool isGearDetected() const {
		return gearDetected;
	}

	bool isGoalDetected() const {
		return goalDetected;
	}

	double getXOffset() const {
		return xOffset;
	}

	double getYOffset() const {
		return yOffset;
	}
	void PrintValues();

};

#endif
