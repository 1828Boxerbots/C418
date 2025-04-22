#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>

#include "../PortManager.hpp"

namespace C418
{
    class IntakeSubsystem : public frc2::SubsystemBase
    {
    public:
        IntakeSubsystem();
        ~IntakeSubsystem();

        void Init();
        void Periodic() override;

        frc2::CommandPtr IntakeLowCmd(double speed);
        frc2::CommandPtr IntakeMidCmd(double speed);
        frc2::CommandPtr IntakeUpperCmd(double speed);
        frc2::CommandPtr IntakeAllCmd(double speed);

    protected:
    private:
        ctre::phoenix::motorcontrol::can::VictorSPX m_LowerIntake{(int)PortManager::Instance().GetCANId("IntakeLow")};
        ctre::phoenix::motorcontrol::can::VictorSPX m_MidIntake{(int)PortManager::Instance().GetCANId("IntakeMid")};
        ctre::phoenix::motorcontrol::can::VictorSPX m_UpperIntake{(int)PortManager::Instance().GetCANId("IntakeTop")};
    };
}