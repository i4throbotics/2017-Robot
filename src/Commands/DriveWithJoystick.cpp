
#include "DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() : Command() {
	Requires(Robot::chassis.get());

}

void DriveWithJoystick::Initialize() {

}

void DriveWithJoystick::Execute() {
	Robot::chassis->CartesianDrive(Robot::oi->getLeftXAxis(),
			Robot::oi->getLeftYAxis(), Robot::oi->getRightXAxis());

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
