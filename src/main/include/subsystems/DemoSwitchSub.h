#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMTalonSRX.h>
#include "Constants.h"
#include <frc2/command/CommandPtr.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/Drive/DifferentialDrive.h>
#include <frc2/command/RunCommand.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <frc/digitalinput.h>
#include <frc/smartdashboard/SmartDashboard.h>





class DemoSwitchSub : public frc2::SubsystemBase 
{
    private:

    static inline frc::DigitalInput m_DemoSwitch{DemoModeConstants::kDemoSwitchPort};

    void DemoSwitchPeriodic();

    public:
    
void Periodic() override;

static bool Readswitch();



};
    