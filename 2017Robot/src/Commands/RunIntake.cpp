#include "RunIntake.h"
#include "../Subsystems/Intake.h"
RunIntake::RunIntake() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void RunIntake::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RunIntake::Execute() {
	Robot::intake->setSpeed(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool RunIntake::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunIntake::End() {
	Robot::intake->setSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunIntake::Interrupted() {
	Robot::intake->setSpeed(0);
}
