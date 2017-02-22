#include "DriveWithJoystick.h"
#include "../Subsystems/Chassis.h"

DriveWithJoystick::DriveWithJoystick() :
		Command() {
	Requires(Robot::chassis.get());

}

void DriveWithJoystick::Initialize() {

}

void DriveWithJoystick::Execute() {
//	SmartDashboard::PutNumber("BL V", Robot::chassis->GetBLVolt() / Robot::driverStation->GetBatteryVoltage());
//	SmartDashboard::PutNumber("BR V", Robot::chassis->GetBRVolt() / Robot::driverStation->GetBatteryVoltage());
//	SmartDashboard::PutNumber("FL V", Robot::chassis->GetFLVolt() / Robot::driverStation->GetBatteryVoltage());
//	SmartDashboard::PutNumber("FR V", Robot::chassis->GetFRVolt() / Robot::driverStation->GetBatteryVoltage());
	if (SmartDashboard::GetBoolean("SmartDashboard Drive", false)) {
		Robot::chassis->CartesianDrive(SmartDashboard::GetNumber("x", 0),
				SmartDashboard::GetNumber("y", 0),
				SmartDashboard::GetNumber("rotate", 0), false);
	}
	else if(SmartDashboard::GetBoolean("Individual Drive",false)){
		Robot::chassis->SetBLSpeed(SmartDashboard::GetNumber("BLS", 0));
		Robot::chassis->SetFLSpeed(SmartDashboard::GetNumber("FLS", 0));
		Robot::chassis->SetBRSpeed(SmartDashboard::GetNumber("BRS", 0));
		Robot::chassis->SetFRSpeed(SmartDashboard::GetNumber("FRS", 0));
	}
	else if(!Robot::chassis->IsFlipped()){
		Robot::chassis->CartesianDrive(Robot::oi->getLeftXAxis(),
				Robot::oi->getLeftYAxis(), Robot::oi->getRightXAxis());
	}
	else{
		Robot::chassis->CartesianDrive(-Robot::oi->getLeftXAxis(),
						-Robot::oi->getLeftYAxis(), Robot::oi->getRightXAxis());
	}
}

bool DriveWithJoystick::IsFinished() {
	return false;
}

void DriveWithJoystick::End() {
	Robot::chassis->CartesianDrive(0, 0, 0);
}

void DriveWithJoystick::Interrupted() {
	Robot::chassis->CartesianDrive(0, 0, 0);
}
