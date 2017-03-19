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
std::unique_ptr<I2C> Robot::wire;

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

	SmartDashboard::PutBoolean("SmartDashboard Drive", false);
	SmartDashboard::PutNumber("x", 0.0);
	SmartDashboard::PutNumber("y", 0.0);
	SmartDashboard::PutNumber("rotate", 0.0);
	SmartDashboard::PutNumber("Climb Speed", 0);
	SmartDashboard::PutNumber("Ramp Target Position", 0);
	SmartDashboard::PutNumber("Ramp Tolerance", 3);
	SmartDashboard::PutNumber("Ramp Speed", 1);

	SmartDashboard::PutNumber("Shooting Ramp Speed", 0.04);
	SmartDashboard::PutNumber("Stationary Ramp Speed", 0.0);

	SmartDashboard::PutString("Front", "INTAKE");
	SmartDashboard::PutNumber("rotate P", 0);
	SmartDashboard::PutNumber("rotate I", 0);
	SmartDashboard::PutNumber("rotate D", 0);
	SmartDashboard::PutNumber("rotate tolerance (degrees)", 0);

}

void Robot::DisabledInit() {

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
	SmartDashboard::PutNumber("Ramp Counter", Robot::shooterRamp->getCount());

}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

