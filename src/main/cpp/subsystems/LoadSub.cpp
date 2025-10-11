// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LoadSub.h"


LoadSub::LoadSub() = default;

// This method will be called once per scheduler run
void LoadSub::Periodic()
 {

  frc::SmartDashboard::PutNumber("Higher Inner Motor: ", m_HigherInnerMotor.GetMotorOutputVoltage());
  frc::SmartDashboard::PutNumber("Lower Inner Motor: ",  m_IntakeMotor.GetMotorOutputVoltage());
  frc::SmartDashboard::PutNumber("Intake Motor: ", m_IntakeMotor.GetMotorOutputVoltage());
  
}

frc2::RunCommand LoadSub::LoadAll(double value)
{
    [this, value] 
    {
        m_HigherInnerMotor.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput,value);
        m_LowerInnerMotor.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput,value);
        m_IntakeMotor.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput,value);
    };
    //{Reference?};
};

frc2::RunCommand LoadSub::LoadLower(double value)
{
    [this, value]
    {
        m_LowerInnerMotor.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, value);
    };
};


frc2::RunCommand LoadSub::LoadUpper(double value)
{

    [this, value]
    {
     m_HigherInnerMotor.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, value);
    };
};


frc2::RunCommand LoadSub::LoadIntake(double value)
{

    [this, value]
    {
        m_IntakeMotor.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, value);
    };
};