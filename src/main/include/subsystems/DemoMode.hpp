#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>

#include "PortManager.hpp"

namespace C418
{
    class DemoMode : public frc2::SubsystemBase
    {
    public:
        DemoMode();
        ~DemoMode();

        void Init();
        void Periodic() override;

        static bool GetDemoMode() { return s_DemoModeEnabled; }

    protected:
    private:
        frc::DigitalInput m_DemoModeSwitch{(int)PortManager::Instance().GetDIOPort("DemoModeSwitch")};
        static bool s_DemoModeEnabled;
    };
}