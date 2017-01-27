#include "PIDShootRotate.h"

PIDShootRotate::PIDShootRotate() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
	errorLast = 0;
	errorDifference = 0;
	errorSum = 0;
	speed = 0;
}

// Called just before this Command runs the first time
void PIDShootRotate::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void PIDShootRotate::Execute() {

		double error = 0; //(speedGoal - (Robot::shooter->getVolt() / 12));//normalize volts to fractional speed
		//TODO:adjust error calculation for position
		errorDifference = error - errorLast;
		errorLast = error;
		errorSum += error;
		speed = (K_P * error)
				+ (K_I * errorSum)
				+ (K_D * errorDifference);
		Robot::shooter->setSpeed(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool PIDShootRotate::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PIDShootRotate::End() {
	Robot::shooter->setSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDShootRotate::Interrupted() {
	Robot::shooter->setSpeed(0);
}
