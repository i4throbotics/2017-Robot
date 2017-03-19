#include "ManualRamp.h"

ManualRamp::ManualRamp(bool up) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	goUp=up;
}

// Called just before this Command runs the first time
void ManualRamp::Initialize() {
	goal=Robot::shooterRamp->getCount();
	if(goUp)
		goal+=3;
	else
		goal-=3;
}
// Called repeatedly when this Command is scheduled to run
void ManualRamp::Execute() {
	if(goUp){
		Robot::shooterRamp->setRampSpeed(SmartDashboard::GetNumber("Ramp Speed", 0));
	}
	else{
		Robot::shooterRamp->setRampSpeed(-SmartDashboard::GetNumber("Ramp Speed", 0));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ManualRamp::IsFinished() {
	if(goUp){
		return Robot::shooterRamp->getCount()>=goal;
	}
	else{
		return Robot::shooterRamp->getCount()<=goal;
	}
}

// Called once after isFinished returns true
void ManualRamp::End() {
	Robot::shooterRamp->setRampSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManualRamp::Interrupted() {
	Robot::shooterRamp->setRampSpeed(0);
}
