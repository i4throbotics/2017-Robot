// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::chassisFrontLeft;
std::shared_ptr<CANTalon> RobotMap::chassisFrontRight;
std::shared_ptr<CANTalon> RobotMap::chassisBackLeft;
std::shared_ptr<CANTalon> RobotMap::chassisBackRight;
std::shared_ptr<RobotDrive> RobotMap::chassisRobotDrive;

std::shared_ptr<SpeedController> RobotMap::liftingMechHighLifty;
std::shared_ptr<SpeedController> RobotMap::liftingMechLowLifty;

std::shared_ptr<CANTalon> RobotMap::intakeWheels;
std::shared_ptr<SpeedController> RobotMap::intakeLift;

std::shared_ptr<Encoder> RobotMap::chassisFrontLeftEncoder;
std::shared_ptr<Encoder> RobotMap::chassisFrontRightEncoder;
std::shared_ptr<Encoder> RobotMap::chassisBackLeftEncoder;
std::shared_ptr<Encoder> RobotMap::chassisBackRightEncoder;
std::shared_ptr<Encoder> RobotMap::intakeLiftEncoder;

//std::shared_ptr<Encoder> RobotMap::shooterEncoder;
std::shared_ptr<CANTalon> RobotMap::shooterMotor;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    chassisFrontLeft.reset(new CANTalon(3));
    lw->AddActuator("Chassis", "FrontLeft", chassisFrontLeft);
    
    chassisBackRight.reset(new CANTalon(2));
    lw->AddActuator("Chassis", "FrontRight", chassisFrontRight);
    
    chassisBackLeft.reset(new CANTalon(6));
    lw->AddActuator("Chassis", "BackLeft", chassisBackLeft);
    
    chassisFrontRight.reset(new CANTalon(1));
    lw->AddActuator("Chassis", "BackRight", chassisBackRight);
    
    chassisRobotDrive.reset(new RobotDrive(chassisFrontLeft, chassisBackLeft,
              chassisFrontRight, chassisBackRight));
    
    chassisRobotDrive->SetSafetyEnabled(true);
        chassisRobotDrive->SetExpiration(0.1);
        chassisRobotDrive->SetSensitivity(0.5);
        chassisRobotDrive->SetMaxOutput(1.0);
        //chassisRobotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
        //chassisRobotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
        //chassisRobotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
        //chassisRobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, false);


    liftingMechHighLifty.reset(new VictorSP(0));
    liftingMechLowLifty.reset(new VictorSP(1));
    //lw->AddActuator("LiftingMech", "liftingMotor", std::static_pointer_cast<VictorSP>(liftingMechliftingMotor));
    
   intakeWheels .reset(new CANTalon(5));
    //lw->AddActuator("Intake", "Lift", intakeWheels);

    intakeLift.reset(new VictorSP(2));
    //lw->AddActuator("Intake", "Wheels", std::static_pointer_cast<VictorSP>(intakeLift));

    chassisFrontRightEncoder.reset(new Encoder(0,1, false, Encoder::k4X));
    lw->AddSensor("Chassis", "FrontRightEncoder", std::static_pointer_cast<Encoder>(chassisFrontRightEncoder));
    chassisBackRightEncoder.reset(new Encoder(2,3, false, Encoder::k4X));
    lw->AddSensor("Chassis", "BackRightEncoder", std::static_pointer_cast<Encoder>(chassisBackRightEncoder));
    chassisFrontLeftEncoder.reset(new Encoder(4,5, true, Encoder::k4X));
    lw->AddSensor("Chassis", "FrontLeftEncoder", std::static_pointer_cast<Encoder>(chassisFrontLeftEncoder));

    chassisBackLeftEncoder.reset(new Encoder(8,9, true, Encoder::k4X));
    lw->AddSensor("Chassis", "BackLeftEncoder", std::static_pointer_cast<Encoder>(chassisBackLeftEncoder));
    intakeLiftEncoder.reset(new Encoder(6,7, false, Encoder::k4X));
    lw->AddSensor("Intake", "intakeLiftEncoder", std::static_pointer_cast<Encoder>(intakeLiftEncoder));

    shooterMotor.reset(new CANTalon(4));
   // shooterEncoder.reset(new Encoder(8,9, false, Encoder::k4X));
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
