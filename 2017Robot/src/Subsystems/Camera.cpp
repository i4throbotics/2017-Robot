// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Camera.h"
#include "../RobotMap.h"
#include "../Commands/UpdateCamera.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Camera::Camera() :
		Subsystem("Camera") {
	wire.reset(new I2C(I2C::Port::kOnboard, 4));
	gearDetected = false;
	goalDetected = false;
	angularOffset = 0;
	xOffset = 0;
	yOffset = 0;
}

void Camera::InitDefaultCommand() {
	SetDefaultCommand(new UpdateCamera());
}

void Camera::Update() {
	uint8_t buffer[4 * sizeof(float)];
	float temp;
	wire->Read(0, 4 * sizeof(float), &buffer[0]);
	std::memcpy(&temp, &buffer[0 * sizeof(float)], sizeof(float));
	if ((int) temp == -1) {
		goalDetected = false;
		gearDetected = false;
	}
	else if ((int) temp == 0) {
		goalDetected = true;
		gearDetected = false;
	}
	else if ((int) temp == 1) {
		goalDetected = false;
		gearDetected = true;
	}
	std::memcpy(&temp, &buffer[1 * sizeof(float)], sizeof(float));
	angularOffset = temp;
	std::memcpy(&temp, &buffer[2 * sizeof(float)], sizeof(float));
	xOffset = temp;
	std::memcpy(&temp, &buffer[3 * sizeof(float)], sizeof(float));
	yOffset = temp;
}

void Camera::PrintValues(){
	SmartDashboard::PutNumber("y Offset", yOffset);
	SmartDashboard::PutNumber("x Offset", xOffset);
	SmartDashboard::PutNumber("angular offset", angularOffset);
	SmartDashboard::PutBoolean("gear detected", gearDetected);
	SmartDashboard::PutBoolean("goal detected", goalDetected);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

