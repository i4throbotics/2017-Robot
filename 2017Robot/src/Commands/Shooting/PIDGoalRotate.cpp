#include "PIDGoalRotate.h"

PIDGoalRotate::PIDGoalRotate() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());
	errorLast = 0;
	errorDifference = 0;
	errorSum = 0;
	speed = 0;
}

// Called just before this Command runs the first time
void PIDGoalRotate::Initialize() {
	/**kP = SmartDashboard::GetNumber("rotate P", 0);
	kI = SmartDashboard::GetNumber("rotate I", 0);
	kD = SmartDashboard::GetNumber("rotate D", 0);
	tolerance = SmartDashboard::GetNumber("rotate tolerance (degrees)", 0)*(M_PI/180);**/
	SmartDashboard::PutString("Status","STARTING");
}
// Called repeatedly when this Command is scheduled to run
void PIDGoalRotate::Execute() {

		double error = 0 - Robot::camera->getAngularOffset();
		if(error<0){
			error=-std::sqrt(-error);
		}
		else{
			error=std::sqrt(error);
		}
		SmartDashboard::PutNumber("error",error);
		errorDifference = error - errorLast;
		errorLast = error;
		errorSum += error;
		speed = (kP * error)
				+ (kI * errorSum)
				+ (kD * errorDifference);
		SmartDashboard::PutNumber("speed",speed);
		Robot::chassis->CartesianDrive(0, 0, speed,false);
}

// Make this return true when this Command no longer needs to run execute()
bool PIDGoalRotate::IsFinished() {
	return (std::fabs(Robot::camera->getAngularOffset()) <= tolerance);
}

// Called once after isFinished returns true
void PIDGoalRotate::End() {
	SmartDashboard::PutString("Status","DONE");
	Robot::chassis->CartesianDrive(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDGoalRotate::Interrupted() {
	Robot::chassis->CartesianDrive(0, 0, 0);
}
