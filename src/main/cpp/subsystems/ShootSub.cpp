// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShootSub.h"
#include "subsystems/DemoSwitchSub.h"

ShootSub::ShootSub() = default;

// This method will be called once per scheduler run
void ShootSub::Periodic() 
{

 frc::SmartDashboard::PutNumber("Higher Inner Motor: ", m_ShootMotorA.GetMotorOutputVoltage());
 frc::SmartDashboard::PutNumber("Lower Inner Motor: ",  m_ShootMotorB.GetMotorOutputVoltage());
 
}

frc2::RunCommand ShootSub::Shoot(double value) 
{
    if (DemoSwitchSub::Readswitch() == true)
   {
    [this, value] 
    {
        
       
        m_ShootMotorA.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, value*DemoModeConstants::kDemoShootScale);
        m_ShootMotorB.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, value*DemoModeConstants::kDemoShootScale);
    };
   }

   else
   {
    [this, value] 
    {
       
        m_ShootMotorA.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, value);
        m_ShootMotorB.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, value);
    };
   }
};