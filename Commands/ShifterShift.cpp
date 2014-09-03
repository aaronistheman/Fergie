// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "ShifterShift.h"
#include "SmartDashboard/SmartDashboard.h"
ShifterShift::ShifterShift() 
: isForward(true)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shifter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void ShifterShift::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void ShifterShift::Execute() {
	if(Robot::shifter->shifterDoubleSolenoid->Get() == DoubleSolenoid::kForward) 
	{
		Robot::shifter->shifterDoubleSolenoid->Set(DoubleSolenoid::kReverse);
		isForward = false;
	}
	else
	{
		Robot::shifter->shifterDoubleSolenoid->Set(DoubleSolenoid::kForward);
		isForward = true;
	}
	
	SmartDashboard::PutBoolean("isForward Gear", isForward);
}
// Make this return true when this Command no longer needs to run execute()
bool ShifterShift::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void ShifterShift::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShifterShift::Interrupted() {
}
