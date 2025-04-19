#include "subsystems/DriveSubsystem.hpp"

namespace C418
{
    DriveSubsystem::DriveSubsystem()
    {
        SetName("DriveSubsystem");
    }

    DriveSubsystem::~DriveSubsystem()
    {

    }

    void DriveSubsystem::Init()
    {
        // Configure Left Side
        bool invertLeft = true;
        m_DriveMotor1.SetInverted(invertLeft);
        m_DriveMotor3.SetInverted(invertLeft);
        m_DriveMotor3.Follow(m_DriveMotor1);

        // Configure Right 
        bool invertRight = false;
        m_DriveMotor2.SetInverted(invertRight);
        m_DriveMotor4.SetInverted(invertRight);
        m_DriveMotor4.Follow(m_DriveMotor2);

        // Zero the motors
        m_Drive.ArcadeDrive(0.0, 0.0);
    }

    void DriveSubsystem::Periodic()
    {
        // TODO: Check for demo mode
        m_Drive.SetMaxOutput(1.0);
    }

    void DriveSubsystem::Drive(double x, double y)
    {
        m_Drive.ArcadeDrive(x, y);
    }
}