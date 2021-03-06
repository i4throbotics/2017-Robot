// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "ShooterRamp.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

ShooterRamp::ShooterRamp() :
		Subsystem("ShooterRamp") {
	Ramp = RobotMap::shooterRamp;
	RampCounter = RobotMap::shooterRampCounter;
	totalCount=0;
	lastCount=0;
}

void ShooterRamp::InitDefaultCommand() {
	//SetDefaultCommand(new ShootRamp());
}



void ShooterRamp::setRampSpeed(double speed){
	Ramp->Set(speed);
}

int ShooterRamp::getCount(){
	int countChange= RampCounter->Get()-lastCount;
	lastCount=RampCounter->Get();
	if(Ramp->Get()<0){
		totalCount-= countChange;
	}
	else{
		totalCount+= countChange;
	}
	return totalCount;
}
