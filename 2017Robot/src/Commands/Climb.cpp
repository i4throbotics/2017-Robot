#include "Climb.h"
#include "../Subsystems/Climber.h"

Climb::Climb() :
		Command() {
	Requires(Robot::climber.get());
}

void Climb::Initialize() {

}

void Climb::Execute() {
	Robot::climber->setSpeed(Robot::oi->getTriggerAxis());
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

