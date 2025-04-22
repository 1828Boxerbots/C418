#include "subsystems/IntakeSubsystem.hpp"

#include <frc2/command/StartEndCommand.h>

namespace C418
{
    IntakeSubsystem::IntakeSubsystem()
    {
        SetName("IntakeSubystem");
    }

    IntakeSubsystem::~IntakeSubsystem()
    {
        // NOTE: Currently does nothing
    }

    void IntakeSubsystem::Init()
    {
        // NOTE: Currently does nothing
    }

    void IntakeSubsystem::Periodic()
    {
        // NOTE: Currently does nothing
    }

    frc2::CommandPtr IntakeSubsystem::IntakeLowCmd(double speed)
    {
        return StartEnd(
            [this, speed]
            {
                // Set Motor to desired speed
                m_LowerIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
            },
            [this]
            {
                // Zero Motor Output
                m_LowerIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
            });
    }

    frc2::CommandPtr IntakeSubsystem::IntakeMidCmd(double speed)
    {
        return StartEnd(
            [this, speed]
            {
                // Set Motor to desired speed
                m_MidIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
            },
            [this]
            {
                // Zero Motor Output
                m_MidIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
            });
    }

    frc2::CommandPtr IntakeSubsystem::IntakeUpperCmd(double speed)
    {
        return StartEnd(
            [this, speed]
            {
                // Set Motor to desired speed
                m_UpperIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
            },
            [this]
            {
                // Zero Motor Output
                m_UpperIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
            });
    }

    frc2::CommandPtr IntakeSubsystem::IntakeAllCmd(double speed)
    {
        return StartEnd(
            [this, speed]
            {
                m_LowerIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
                m_MidIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
                m_UpperIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, speed);
            },
            [this]
            {
                m_LowerIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
                m_MidIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
                m_UpperIntake.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, 0.0);
            });
    }
}