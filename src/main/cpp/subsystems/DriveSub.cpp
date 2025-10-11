// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSub.h"
#include "subsystems/DemoSwitchSub.h"




DriveSub::DriveSub()
{
   //Inverts the motors

    m_leftMotorB.SetInverted(true);


   //Sets the followers

    m_leftMotorB.Follow(m_leftMotorA);
    m_RightMotorB.Follow(m_RightMotorA);
}

// This method will be called once per scheduler run
void DriveSub::Periodic() 
{
  frc::SmartDashboard::PutNumber("LeftA Motor: ", m_leftMotorA.GetMotorOutputVoltage());
  frc::SmartDashboard::PutNumber("LeftB Motor: ",  m_leftMotorA.GetMotorOutputVoltage());
  frc::SmartDashboard::PutNumber("RightA Motor: ", m_RightMotorA.GetMotorOutputVoltage());
  frc::SmartDashboard::PutNumber("RightB Motor: ", m_RightMotorB.GetMotorOutputVoltage());
}

//Feed RC the Left joystick that controls the Y of the robot (side to side), and the right joystick that controls the X of the robot (front and back)
 frc2::RunCommand DriveSub::RC(double LeftY, double RightX) // make this the run command
{   

   if(DemoSwitchSub::Readswitch() == true)
   {
      //Scale down the Left and Right joysticks by a certain value

      int ScaledLeftY = LeftY*DemoModeConstants::kDemoDriveScale;
      int ScaledRightX = RightX*DemoModeConstants::kDemoDriveScale;

      //Convert the Left and Right joysticks (now scaled) into real world values (feet per second)

      units::feet_per_second_t DeliveredLeftY = ScaledLeftY *  DriveConstants::kSpeed;
      units::feet_per_second_t DeliveredRightX = ScaledRightX *  DriveConstants::kSpeed;

     m_drive.ArcadeDrive(ScaledLeftY, ScaledRightX);

      //Create wheelspeeds variable equal to Real world value
     frc::DifferentialDriveWheelSpeeds wheelSpeeds{DeliveredLeftY, DeliveredRightX};
     auto [linearVelocity, vy, angularVelocity] = m_kinematics.ToChassisSpeeds(wheelSpeeds);
   }
   else
   {
      //Convert the Left and Right joysticks into real world values (feet per second)


      units::feet_per_second_t DeliveredLeftY = LeftY *  DriveConstants::kSpeed;
      units::feet_per_second_t DeliveredRightX = RightX *  DriveConstants::kSpeed;

      //feed the arcade drive the joysticks value

      m_drive.ArcadeDrive(LeftY, RightX);

      //Create wheelspeeds variable equal to Real world values

      frc::DifferentialDriveWheelSpeeds wheelSpeeds{DeliveredLeftY, DeliveredRightX};
      auto [linearVelocity, vy, angularVelocity] = m_kinematics.ToChassisSpeeds(wheelSpeeds);

   }
}



void DriveSub::StopAllMotors(double value)
{
   // m_leftMotorA.Set(0);
    //m_leftMotorB.Set(0);
   // m_RightMotorA.Set(0);
   // m_RightMotorB.Set(0);
}

void DriveSub::SetLeftMotors(double value)
{
   // m_leftMotorA.Set(value);
   // m_leftMotorB.Set(value);
}

 void DriveSub::SetRightMotors(double value)
 {
    // m_RightMotorA.Set(value);
    //m_RightMotorB.Set(value);
 }

 frc2::CommandPtr DriveSub::Drive()
 {

 }