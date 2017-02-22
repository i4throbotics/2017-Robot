#include "PIDGoalRotate.h"

PIDGoalRotate::PIDGoalRotate() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());
	errorLast = 0;
	errorDifference = 0;
	errorSum = 0;
	speed = 0;
}

// Called just before this Command runs the first time
void PIDGoalRotate::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void PIDGoalRotate::Execute() {

		double error = Robot::camera->getAngularOffset();
		errorDifference = error - errorLast;
		errorLast = error;
		errorSum += error;
		speed = (kP * error)
				+ (kI * errorSum)
				+ (kD * errorDifference);
		Robot::chassis->CartesianDrive(0, 0, speed);
}

// Make this return true when this Command no longer needs to run execute()
bool PIDGoalRotate::IsFinished() {
	return (std::fabs(Robot::camera->getAngularOffset()) <= tolerance);
}

// Called once after isFinished returns true
void PIDGoalRotate::End() {
	Robot::chassis->CartesianDrive(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDGoalRotate::Interrupted() {
	Robot::chassis->CartesianDrive(0, 0, 0);
}
