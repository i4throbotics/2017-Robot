#include "PIDGoalMove.h"

PIDGoalMove::PIDGoalMove() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());
	errorLast = 0;
	errorDifference = 0;
	errorSum = 0;
	speed = 0;
}

// Called just before this Command runs the first time
void PIDGoalMove::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void PIDGoalMove::Execute() {

		double error = Robot::camera->getYOffset();
		errorDifference = error - errorLast;
		errorLast = error;
		errorSum += error;
		speed = (kP * error)
				+ (kI * errorSum)
				+ (kD * errorDifference);
		Robot::chassis->CartesianDrive(0, speed, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool PIDGoalMove::IsFinished() {
	return (Robot::camera->getYOffset() <= outerTolerance && Robot::camera->getYOffset() >= innerTolerance);
}

// Called once after isFinished returns true
void PIDGoalMove::End() {
	Robot::chassis->CartesianDrive(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDGoalMove::Interrupted() {
	Robot::chassis->CartesianDrive(0, 0, 0);
}
