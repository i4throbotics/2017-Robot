#include "Robot.h"
#include <climits>//added
#include <iostream>
std::shared_ptr<Chassis> Robot::chassis;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Camera> Robot::camera;
std::unique_ptr<OI> Robot::oi;
std::unique_ptr<I2C> Robot::wire;
int Robot::x;
bool Robot::done;
std::ofstream file;


void Robot::RobotInit() {
	RobotMap::init();

	chassis.reset(new Chassis());
	shooter.reset(new Shooter());
	camera.reset(new Camera());

	oi.reset(new OI());
	wire.reset(new I2C(I2C::Port::kOnboard, 4));
	x = 0;
	done = false;
	file.open("/home/lvuser/cameratestoutput.txt");
	SmartDashboard::PutString("Auto Program", "Low Bar");
	SmartDashboard::PutBoolean("Backwards", false);

	SmartDashboard::PutBoolean("Custom Auto", false);
	SmartDashboard::PutNumber("Auto Drive Distance", 1100);
	SmartDashboard::PutNumber("Auto Drive Speed", 0.5);
	SmartDashboard::PutNumber("shooter speed", 0);
	SmartDashboard::PutNumber("kP", 1);
	SmartDashboard::PutNumber("kI", 0);
	SmartDashboard::PutNumber("kD", 0.1);



}

void Robot::DisabledInit() {
	file.close();
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
//
//	uint8_t buffer[sizeof(float)];
//	float result;
//	Robot::wire->Read(0, sizeof(float), &buffer[0]);
//	std::memcpy(&result, &buffer[0], sizeof(float));
//	std::cout<<result<<std::endl;


}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

