// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include  <frc/motorcontrol/PWMTalonSRX.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/RunCommand.h>
#include "Constants.h"
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

#include <frc/smartdashboard/SmartDashboard.h>

class LoadSub : public frc2::SubsystemBase {
 public:
  LoadSub();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

frc2::RunCommand LoadAll(double value);
frc2::RunCommand LoadLower(double value);
frc2::RunCommand LoadUpper(double value);
frc2::RunCommand LoadIntake(double value);



 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

ctre::phoenix::motorcontrol::can::TalonSRX m_LowerInnerMotor{LoadConstants::kHigherInnerMotorPort};
ctre::phoenix::motorcontrol::can::TalonSRX m_HigherInnerMotor{LoadConstants::kLowerInnerMotorPort};
ctre::phoenix::motorcontrol::can::TalonSRX m_IntakeMotor{LoadConstants::kIntakeMotorPort};



};
