#include "FlipChassis.h"
FlipChassis::FlipChassis() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void FlipChassis::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FlipChassis::Execute() {
	Robot::chassis->FlipDirection();
	if(Robot::chassis->IsFlipped()){
		SmartDashboard::PutString("Front", "SHOOTER");
	}
	else{
		SmartDashboard::PutString("Front", "INTAKE");
	}
}

// Make this return true when this Command no longer needs to run execute()
bool FlipChassis::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void FlipChassis::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlipChassis::Interrupted() {
}
