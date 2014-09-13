// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "TripleMotor.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static SpeedController* catapultTalon7;
	static SpeedController* catapultTalon8;
	static DoubleSolenoid* catapultCatapultDoubleSolenoid;
	static SpeedController* chassisTalon1;
	static SpeedController* chassisTalon2;
	static SpeedController* chassisTalon3;
	static SpeedController* chassisTalon4;
	static SpeedController* chassisTalon5;
	static SpeedController* chassisTalon6;
	static SpeedController* intakeTalon9;
	static DoubleSolenoid* intakeIntakeDoubleSolenoid;
	static Relay* intakeLights;
	static Compressor* pressurizerCompressor;
	static DoubleSolenoid* shifterShifterDoubleSolenoid;
	static DoubleSolenoid* huggerHuggerDoubleSolenoid;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static TripleMotor* leftDrive;
	static TripleMotor* rightDrive;
	static RobotDrive* chassisRobotDrive;
	static void init();
};
#endif
