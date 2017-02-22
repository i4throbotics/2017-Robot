#include "MoveRamp.h"

MoveRamp::MoveRamp(bool up) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	goUp=up;
}

// Called just before this Command runs the first time
void MoveRamp::Initialize() {
	if(goUp && SmartDashboard::GetNumber("Ramp Target Position", 0)<130){
		SmartDashboard::PutNumber("Ramp Target Position",SmartDashboard::GetNumber("Ramp Target Position", 0)+10);
	}
	else if( !goUp && SmartDashboard::GetNumber("Ramp Target Position", 0)>=10){
		SmartDashboard::PutNumber("Ramp Target Position",SmartDashboard::GetNumber("Ramp Target Position", 0)-10);
	}
}
// Called repeatedly when this Command is scheduled to run
void MoveRamp::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool MoveRamp::IsFinished() {

	return true;
}

// Called once after isFinished returns true
void MoveRamp::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveRamp::Interrupted() {
}
