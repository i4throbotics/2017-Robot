// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef PIDGoalMove_H
#define PIDGoalMove_H


#include "Commands/Subsystem.h"
#include "../../Robot.h"
#include "../../RobotMap.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class PIDGoalMove: public Command {
private:
	double const innerTolerance = 12*1;
	double const outerTolerance = 12*5;
	double const kP = 0.8;
	double const kI = 0.5;
	double const kD = 0.1;
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	PIDGoalMove();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
	double errorLast;
	double errorDifference;
	double errorSum;
	double speed;

};

#endif
