#include "AutoRamp.h"

AutoRamp::AutoRamp(int goal) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->goal=goal;
}

// Called just before this Command runs the first time
void AutoRamp::Initialize() {
	goUp = goal>Robot::shooterRamp->getCount();
}
// Called repeatedly when this Command is scheduled to run
void AutoRamp::Execute() {
	if(goUp){
		Robot::shooterRamp->setRampSpeed(SmartDashboard::GetNumber("Ramp Speed", 0));
	}
	else{
		Robot::shooterRamp->setRampSpeed(-SmartDashboard::GetNumber("Ramp Speed", 0));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRamp::IsFinished() {
	if(goUp){
		return Robot::shooterRamp->getCount()>=goal;
	}
	else{
		return Robot::shooterRamp->getCount()<=goal;
	}
}

// Called once after isFinished returns true
void AutoRamp::End() {
	Robot::shooterRamp->setRampSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRamp::Interrupted() {
	Robot::shooterRamp->setRampSpeed(0);
}
