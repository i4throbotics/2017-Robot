#include "Blender.h"
#include "../RobotMap.h"
Blender::Blender() :
		Subsystem("Blender") {
	blenderMotor = RobotMap::blenderMotor;
}

void Blender::InitDefaultCommand() {

}

void Blender::setSpeed(double speed){
	blenderMotor->Set(speed);
}



// Put methods for controlling this subsystem
// here. Call these from Commands.

