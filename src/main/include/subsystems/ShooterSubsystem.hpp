#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>

#include "../PortManager.hpp"

namespace C418
{
    class ShooterSubsystem : public frc2::SubsystemBase
    {
    public:
        ShooterSubsystem();
        ~ShooterSubsystem();

        void Init();
        void Periodic() override;

        frc2::CommandPtr ShootCmd(double speed, double demoSpeed);

    protected:
    private:
        ctre::phoenix::motorcontrol::can::VictorSPX m_Shooter1{(int)PortManager::Instance().GetCANId("Shoot1")};
        ctre::phoenix::motorcontrol::can::VictorSPX m_Shooter2{(int)PortManager::Instance().GetCANId("Shoot1")};
    };
}