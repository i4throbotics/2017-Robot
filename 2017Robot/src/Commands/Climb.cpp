#include "Climb.h"
#include "../Subsystems/Climber.h"

Climb::Climb() :
		Command() {
}

void Climb::Initialize() {

}

void Climb::Execute() {
	Robot::climber->setSpeed(-SmartDashboard::GetNumber("Climb Speed", 0));
}

bool Climb::IsFinished() {
	return false;
}

void Climb::End() {
	Robot::climber->setSpeed(0);
}

void Climb::Interrupted() {
	Robot::climber->setSpeed(0);
}

