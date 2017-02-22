#include "Robot.h"
#include <climits>//added
#include <iostream>
std::shared_ptr<Chassis> Robot::chassis;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<ShooterRamp> Robot::shooterRamp;
std::shared_ptr<Camera> Robot::camera;
std::shared_ptr<Climber> Robot::climber;
std::shared_ptr<Intake> Robot::intake;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<DriverStation> Robot::driverStation;
std::shared_ptr<Blender> Robot::blender;
std::ofstream file;


void Robot::RobotInit() {
	RobotMap::init();

	chassis.reset(new Chassis());
	shooter.reset(new Shooter());
	shooterRamp.reset(new ShooterRamp());
	camera.reset(new Camera());
	climber.reset(new Climber());
	intake.reset(new Intake());
	blender.reset(new Blender());

	oi.reset(new OI());

	//file.open("/home/lvuser/cameratestoutput.txt");
	SmartDashboard::PutNumber("shooter speed", 0.8);
	SmartDashboard::PutNumber("kP", 1);
	SmartDashboard::PutNumber("kI", 0);
	SmartDashboard::PutNumber("kD", .12);
	SmartDashboard::PutBoolean("SmartDashboard Drive", false);
	SmartDashboard::PutNumber("x", 0.0);
	SmartDashboard::PutNumber("y", 0.0);
	SmartDashboard::PutNumber("rotate", 0.0);
	SmartDashboard::PutNumber("FL V", 0.0);
	SmartDashboard::PutNumber("FR V", 0.0);
	SmartDashboard::PutNumber("BL V", 0.0);
	SmartDashboard::PutNumber("BR V", 0.0);
	SmartDashboard::PutNumber("Climb Speed", 0);
	SmartDashboard::PutNumber("Intake Speed", 0.8);
	SmartDashboard::PutNumber("Ramp Target Position", 0);
	SmartDashboard::PutNumber("Ramp Tolerance", 3);
	SmartDashboard::PutNumber("Ramp Speed", 0.05);

	SmartDashboard::PutBoolean("Individual Drive", false);
	SmartDashboard::PutNumber("BLS",0);
	SmartDashboard::PutNumber("BRS",0);
	SmartDashboard::PutNumber("FLS",0);
	SmartDashboard::PutNumber("FRS",0);
	SmartDashboard::PutNumber("Shooting Ramp Speed", 0.04);
	SmartDashboard::PutNumber("Stationary Ramp Speed", 0.0);


	shooterRamp->resetEncoder();

}

void Robot::DisabledInit() {
	//file.close();
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {

	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Ramp Encoder", Robot::shooterRamp->getEncoder());
	if(chassis->IsFlipped()){
		SmartDashboard::PutString("Front", "SHOOTER");
	}
	else{
		SmartDashboard::PutString("Front", "INTAKE");
	}


}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

