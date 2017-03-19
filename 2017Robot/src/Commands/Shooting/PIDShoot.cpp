#include "PIDShoot.h"

PIDShoot::PIDShoot() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
	errorLast = 0;
	errorDifference = 0;
	errorSum = 0;
	speed=0;
}

// Called just before this Command runs the first time
void PIDShoot::Initialize() {
	Robot::shooter->setSpeed(speed);

}
// Called repeatedly when this Command is scheduled to run
void PIDShoot::Execute() {
		double error = (speedGoal - (Robot::shooter->getVolt() / 12));//normalize volts to fractional speed
		errorDifference = error - errorLast;
		errorLast = error;
		errorSum += error;
		double acceleration = (kP * error)
				+ (kI * errorSum)
				+ (kD * errorDifference);
		speed += acceleration;
		Robot::shooter->setSpeed(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool PIDShoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PIDShoot::End() {
	Robot::shooter->setSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDShoot::Interrupted() {
	Robot::shooter->setSpeed(0);
}
