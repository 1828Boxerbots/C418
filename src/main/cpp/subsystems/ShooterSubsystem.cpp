#include "subsystems/ShooterSubsystem.hpp"

#include "subsystems/DemoMode.hpp"

#include "frc2/command/StartEndCommand.h"

namespace C418
{
    ShooterSubsystem::ShooterSubsystem()
    {
        SetName("ShooterSubsystem");
    }

    ShooterSubsystem::~ShooterSubsystem()
    {
        // NOTE: Currently does nothing
    }

    void ShooterSubsystem::Init()
    {
        // NOTE: Currently does nothing
    }

    void ShooterSubsystem::Periodic()
    {
        // NOTE: Currently does nothing
    }

    frc2::CommandPtr ShooterSubsystem::ShootCmd(double speed, double demoSpeed)
    {
        return StartEnd(
            [this, speed, demoSpeed]
            {
                double desiredSpeed = 0.0;

                if (DemoMode::GetDemoMode())
                {
                    desiredSpeed = demoSpeed;
                }
                else
                {
                    desiredSpeed = speed;
                }

                // Set shooter motors
                m_Shooter1.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, desiredSpeed);
                m_Shooter2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, desiredSpeed);
            },
            [this]
            {
                // Zero Motors
                m_Shooter1.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
                m_Shooter2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
            });
    }
}