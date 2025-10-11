// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

 m_Drive.SetDefaultCommand(frc2::RunCommand(
      [this] {
         m_Drive.RC(-m_driverController.GetLeftY(),
                            -m_driverController.GetRightX());
      },
      {&m_Drive}));
   

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  
  //Right trigger = shoot

    //Reversed
    (m_driverController.LeftBumper() && m_driverController.RightTrigger()).WhileTrue(frc2::CommandPtr(m_Shoot.Shoot(-ShootConstants::kShooterSpeed)));

    //Forward
    (!m_driverController.LeftBumper() && m_driverController.RightTrigger()).WhileTrue(frc2::CommandPtr(m_Shoot.Shoot(ShootConstants::kShooterSpeed)));

//y = load all

    //Reversed
    (m_driverController.LeftBumper() && m_driverController.Y()).WhileTrue(frc2::CommandPtr(m_Load.LoadAll(-ShootConstants::kShooterSpeed)));

    //Forward
    (!m_driverController.LeftBumper() && m_driverController.Y()).WhileTrue(frc2::CommandPtr(m_Load.LoadAll(LoadConstants::kLoadSpeed)));

//x = load Lower

   //Reversed
  (m_driverController.LeftBumper() && m_driverController.X()).WhileTrue(frc2::CommandPtr(m_Load.LoadLower(-LoadConstants::kLoadSpeed)));
 
   //Forward
  (!m_driverController.LeftBumper() && m_driverController.X()).WhileTrue(frc2::CommandPtr(m_Load.LoadLower(LoadConstants::kLoadSpeed)));


//A = Load Intake

  //Reversed
  (m_driverController.LeftBumper() && m_driverController.A()).WhileTrue(frc2::CommandPtr(m_Load.LoadIntake(-LoadConstants::kLoadSpeed)));

  //Forward
  (!m_driverController.LeftBumper() && m_driverController.A()).WhileTrue(frc2::CommandPtr(m_Load.LoadIntake(ShootConstants::kShooterSpeed)));

//B = load Upper

   //Reversed
  (m_driverController.LeftBumper() && m_driverController.B()).WhileTrue(frc2::CommandPtr(m_Load.LoadUpper(-LoadConstants::kLoadSpeed)));

  //Forward
   (!m_driverController.LeftBumper() && m_driverController.B()).WhileTrue(frc2::CommandPtr(m_Load.LoadUpper(ShootConstants::kShooterSpeed)));



};
frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}
