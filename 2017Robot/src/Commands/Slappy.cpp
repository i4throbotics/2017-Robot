#include "Slappy.h"
#include "../Subsystems/Blender.h"
Slappy::Slappy() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::blender.get());
}

// Called just before this Command runs the first time
void Slappy::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Slappy::Execute() {
	Robot::blender->setSpeed(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool Slappy::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Slappy::End() {
	Robot::blender->setSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Slappy::Interrupted() {
	Robot::blender->setSpeed(0);
}
