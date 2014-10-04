// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "AutoDrive.h"
#include "SmartDashboard/SmartDashboard.h"
AutoDrive::AutoDrive() 
: driveDistance(0.0)
, goalDistance(0.0)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	Robot::chassis->encoder1->Reset();
	driveDistance = 0;
}
// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {
	// Update driveDistance and goalDistance
	// Multiply by -1 because the robot drives backwards during
	// low goal autonomous mode
	driveDistance = Robot::chassis->encoder1->Get() * -1;
	goalDistance = Robot::robotPref->GetDouble("goalDistance", 0.0);
	
	// Print to SmartDashboard
	SmartDashboard::PutNumber("driveDistance", driveDistance);
	
	// Make the robot drive
	Robot::chassis->robotDrive->Drive(
			Robot::robotPref->GetDouble("driveSpeed", 0.0),
			Robot::robotPref->GetDouble("driveAngle", 0.0));
}
// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	return driveDistance >= goalDistance;
}
// Called once after isFinished returns true
void AutoDrive::End() {
	Robot::chassis->encoder1->Reset();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {
	Robot::chassis->encoder1->Reset();
}
