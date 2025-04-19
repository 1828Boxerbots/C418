#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>

#include "../PortManager.hpp"

namespace C418
{
    class DriveSubsystem : public frc2::SubsystemBase
    {
        public:
            DriveSubsystem();
            ~DriveSubsystem();

            void Init();
            void Periodic() override;

            void Drive(double x, double y);

        protected:
        private:
            // Left Drive Train
            ctre::phoenix::motorcontrol::can::VictorSPX m_DriveMotor1 { (int)PortManager::Instance().GetCANId("DriveMotor1") };
            ctre::phoenix::motorcontrol::can::VictorSPX m_DriveMotor3 { (int)PortManager::Instance().GetCANId("DriveMotor3") };

            // Right Drive Train
            ctre::phoenix::motorcontrol::can::VictorSPX m_DriveMotor2 { (int)PortManager::Instance().GetCANId("DriveMotor2") };
            ctre::phoenix::motorcontrol::can::VictorSPX m_DriveMotor4 { (int)PortManager::Instance().GetCANId("DriveMotor4") };

            frc::DifferentialDrive m_Drive
            {
                [&] (double output) { m_DriveMotor1.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, output);},
                [&] (double output) { m_DriveMotor2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, output); }
            };
    };
}