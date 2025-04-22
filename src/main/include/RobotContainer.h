// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"
#include "subsystems/DriveSubsystem.hpp"
#include "subsystems/DemoMode.hpp"
#include "subsystems/IntakeSubsystem.hpp"
#include "subsystems/ShooterSubsystem.hpp"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer
{
public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

private:
  void ConfigureBindings();

  frc2::CommandXboxController m_driverController{(int)C418::PortManager::Instance().GetUSBPort("DriveController")};

  // The robot's subsystems are defined here...
  C418::DriveSubsystem m_drive;
  C418::DemoMode m_demoMode;
  C418::IntakeSubsystem m_intake;
  C418::ShooterSubsystem m_shooter;
};
