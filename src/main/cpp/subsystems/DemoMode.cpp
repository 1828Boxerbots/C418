#include "subsystems/DemoMode.hpp"

#include <frc/smartdashboard/SmartDashboard.h>

namespace C418
{
    bool DemoMode::s_DemoModeEnabled = false;

    DemoMode::DemoMode()
    {
        SetName("DemoMode");
    }

    DemoMode::~DemoMode()
    {
        // NOTE: Currently does nothing
    }

    void DemoMode::Init()
    {
        // NOTE: Currently does nothing
    }

    void DemoMode::Periodic()
    {
        s_DemoModeEnabled = m_DemoModeSwitch.Get();

        frc::SmartDashboard::PutBoolean("Demo Mode Enabled", s_DemoModeEnabled);
    }
}