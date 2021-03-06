// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Robot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Catapult* Robot::catapult = 0;
Chassis* Robot::chassis = 0;
Intake* Robot::intake = 0;
Pressurizer* Robot::pressurizer = 0;
Shifter* Robot::shifter = 0;
Hugger* Robot::hugger = 0;
OI* Robot::oi = 0;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Preferences* Robot::robotPref = 0;
void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	catapult = new Catapult();
	chassis = new Chassis();
	intake = new Intake();
	pressurizer = new Pressurizer();
	shifter = new Shifter();
	hugger = new Hugger();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
	robotPref = Preferences::GetInstance();
	
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutoLowGoal();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	Robot::catapult->catapultDoubleSolenoid->Set(DoubleSolenoid::kReverse);
	Robot::intake->intakeDoubleSolenoid->Set(DoubleSolenoid::kReverse);
	Robot::hugger->huggerDoubleSolenoid->Set(DoubleSolenoid::kForward);
	Robot::shifter->shifterDoubleSolenoid->Set(DoubleSolenoid::kReverse);
	// Robot::chassis->robotDrive
	// 				->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
	// Robot::chassis->robotDrive
	// 				->SetInvertedMotor(RobotDrive::kRearRightMotor, false);
  }
	
void Robot::AutonomousInit() {
	// instantiate the command used for the autonomous period
	// autoChooser = new SendableChooser();
	// autoChooser->AddDefault("AutoOneBall", new AutoOneBall());
	// autoChooser->AddObject("AutoDoNothing", new AutoDoNothing());
	// SmartDashboard::PutData("AutoChooser", autoChooser);
	// autonomousCommand = (Command*)(autoChooser->GetSelected());
	
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}
	
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();
}
	
void Robot::TeleopPeriodic() {
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
