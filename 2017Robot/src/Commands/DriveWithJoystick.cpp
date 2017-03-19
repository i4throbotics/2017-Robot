#include "DriveWithJoystick.h"
#include "../Subsystems/Chassis.h"

DriveWithJoystick::DriveWithJoystick() :
		Command() {
	Requires(Robot::chassis.get());

}

void DriveWithJoystick::Initialize() {

}

void DriveWithJoystick::Execute() {
	if (SmartDashboard::GetBoolean("SmartDashboard Drive", false)) {
		Robot::chassis->CartesianDrive(SmartDashboard::GetNumber("x", 0),
				SmartDashboard::GetNumber("y", 0),
				SmartDashboard::GetNumber("rotate", 0), false);
	}
	else if(!Robot::chassis->IsFlipped()){
		Robot::chassis->CartesianDrive(Robot::oi->getLeftXAxis(),
				Robot::oi->getLeftYAxis(), Robot::oi->getRightXAxis());
	}
	else{
		Robot::chassis->CartesianDrive(-Robot::oi->getLeftXAxis(),
						-Robot::oi->getLeftYAxis(), Robot::oi->getRightXAxis());
	}
}

bool DriveWithJoystick::IsFinished() {
	return false;
}

void DriveWithJoystick::End() {
	Robot::chassis->CartesianDrive(0, 0, 0);
}

void DriveWithJoystick::Interrupted() {
	Robot::chassis->CartesianDrive(0, 0, 0);
}
