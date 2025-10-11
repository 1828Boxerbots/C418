// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMTalonSRX.h>
#include <frc2/command/RunCommand.h>
#include "Constants.h"
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

#include <frc/smartdashboard/SmartDashboard.h>

class ShootSub : public frc2::SubsystemBase {
 public:
  ShootSub();

  frc2::RunCommand Shoot(double value);

   void SetShootMotors();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

   ctre::phoenix::motorcontrol::can::TalonSRX m_ShootMotorA{ShootConstants::kShooterPortA};
   ctre::phoenix::motorcontrol::can::TalonSRX m_ShootMotorB{ShootConstants::kShooterPortB};


};
