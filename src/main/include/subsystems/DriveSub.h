// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <units/length.h>
#include <frc2/command/SubsystemBase.h>
#include  <frc/motorcontrol/PWMTalonSRX.h>
#include "Constants.h"
#include <frc2/command/CommandPtr.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/Drive/DifferentialDrive.h>
#include <frc2/command/RunCommand.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

#include <frc/smartdashboard/SmartDashboard.h>


class DriveSub : public frc2::SubsystemBase { 
 public:
  DriveSub();
  frc2::RunCommand RC(double LeftY, double RightX);

///Getters and Setters

void SetAllMotors(double value);

//Commands
 
 frc2::CommandPtr Drive();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

 ctre::phoenix::motorcontrol::can::TalonSRX m_leftMotorA{DriveConstants::kLeftMotorAPort};
 ctre::phoenix::motorcontrol::can::TalonSRX m_leftMotorB{DriveConstants::kLeftMotorBPort};
 ctre::phoenix::motorcontrol::can::TalonSRX m_RightMotorA{DriveConstants::kRightMotorAPort};
 ctre::phoenix::motorcontrol::can::TalonSRX m_RightMotorB{DriveConstants::kRightMotorBPort};


//Differential Drive Kinemeatic object
frc::DifferentialDriveKinematics m_kinematics {DriveConstants::kTrackWidth};



frc::DifferentialDrive m_drive{[&](double output) {m_leftMotorA.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput , output);}, 
                               [&](double output) {m_RightMotorA.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, output);}};






   // make rc the run command of m_Drive acrade drive
  void StopAllMotors(double value);
  void SetLeftMotors(double value);
  void SetRightMotors(double value);

 

 

};