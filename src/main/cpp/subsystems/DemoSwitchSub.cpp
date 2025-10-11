#include "subsystems/DemoSwitchSub.h"



bool DemoSwitchSub::Readswitch()
{
    return m_DemoSwitch.Get();
}

void DemoSwitchSub::Periodic()
{
    frc::SmartDashboard::PutBoolean("Demo Switch value: ", m_DemoSwitch.Get());
   
  
}