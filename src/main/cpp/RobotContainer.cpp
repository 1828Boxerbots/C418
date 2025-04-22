// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/Commands.h>
#include <frc2/command/RunCommand.h>

RobotContainer::RobotContainer()
{
  // Initialize all of your commands and subsystems here
  m_drive.Init();
  m_drive.SetDefaultCommand(
      frc2::RunCommand(
          [this]
          {
            m_drive.Drive(
                m_driverController.GetLeftY(),
                m_driverController.GetRightX());
          }));

  m_demoMode.Init();
  m_intake.Init();
  m_shooter.Init();

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings()
{
  // Shooter
  m_driverController.RightTrigger().WhileTrue(m_shooter.ShootCmd(ShooterConstants::shootSpeed, ShooterConstants::demoShootSpeed));
  (m_driverController.RightTrigger() && m_driverController.LeftBumper()).WhileTrue(m_shooter.ShootCmd(-ShooterConstants::shootSpeed, -ShooterConstants::demoShootSpeed));

  // Intake All
  m_driverController.Y().WhileTrue(m_intake.IntakeAllCmd(IntakeConstants::intakeSpeed));
  (m_driverController.Y() && m_driverController.LeftBumper()).WhileTrue(m_intake.IntakeAllCmd(-IntakeConstants::intakeSpeed));

  // Intake Lower
  m_driverController.X().WhileTrue(m_intake.IntakeLowCmd(IntakeConstants::intakeSpeed));
  (m_driverController.X() && m_driverController.LeftBumper()).WhileTrue(m_intake.IntakeLowCmd(-IntakeConstants::intakeSpeed));

  // Intake Mid
  m_driverController.A().WhileTrue(m_intake.IntakeMidCmd(IntakeConstants::intakeSpeed));
  (m_driverController.A() && m_driverController.LeftBumper()).WhileTrue(m_intake.IntakeMidCmd(-IntakeConstants::intakeSpeed));

  // Intake Upper
  m_driverController.B().WhileTrue(m_intake.IntakeUpperCmd(IntakeConstants::intakeSpeed));
  (m_driverController.B() && m_driverController.LeftBumper()).WhileTrue(m_intake.IntakeUpperCmd(-IntakeConstants::intakeSpeed));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand()
{
  return frc2::cmd::Print("No automonous command configured");
}
