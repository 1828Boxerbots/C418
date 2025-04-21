#pragma once

#include <string>
#include <map>

namespace C418
{
    class PortManager
    {
    public:
        // Enforce singleton access
        PortManager(const PortManager &obj) = delete;
        PortManager &operator=(const PortManager &obj) = delete;

        ~PortManager();

        static PortManager &Instance();

        unsigned int GetCANId(std::string deviceName) { return m_CANPorts[deviceName]; }

        unsigned int GetDIOPort(std::string deviceName) { return m_DIOPorts[deviceName]; }

        unsigned int GetUSBPort(std::string deviceName) { return m_USBPorts[deviceName]; }

    protected:
    private:
        PortManager();

        std::map<std::string, unsigned int> m_CANPorts{
            {"DriveMotor1", 5},
            {"DriveMotor2", 3},
            {"DriveMotor3", 4},
            {"DriveMotor4", 2},
            {"IntakeLow", 7},
            {"IntakeMid", 6},
            {"IntakeTop", 8},
            {"Shoot1", 9},
            {"Shoot2", 10}};

        std::map<std::string, unsigned int> m_DIOPorts{
            {"DemoModeSwtich", 8}};

        std::map<std::string, unsigned int> m_USBPorts{
            {"DriveController", 0}};
    };
}