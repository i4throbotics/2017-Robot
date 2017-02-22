#include "ShootRamp.h"

ShootRamp::ShootRamp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterRamp.get());
}

// Called just before this Command runs the first time
void ShootRamp::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void ShootRamp::Execute() {

	tolerance=SmartDashboard::GetNumber("Ramp Tolerance", 4);
	if (SmartDashboard::GetNumber("Ramp Target Position", 0) - tolerance
			> Robot::shooterRamp->getEncoder()) {
		Robot::shooterRamp->setRampSpeed(SmartDashboard::GetNumber("Ramp Speed", 0.05));
	} else if (SmartDashboard::GetNumber("Ramp Target Position", 0) + tolerance
			< Robot::shooterRamp->getEncoder()) {
		Robot::shooterRamp->setRampSpeed(-SmartDashboard::GetNumber("Ramp Speed", 0.05));
	} else if(Robot::shooter->isRunning()){
		Robot::shooterRamp->setRampSpeed(SmartDashboard::GetNumber("Shooting Ramp Speed", 0.04));
	}
	else{
		Robot::shooterRamp->setRampSpeed(SmartDashboard::GetNumber("Stationary Ramp Speed", 0.03));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShootRamp::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootRamp::End() {
	Robot::shooterRamp->setRampSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootRamp::Interrupted() {
	Robot::shooterRamp->setRampSpeed(0);
}
