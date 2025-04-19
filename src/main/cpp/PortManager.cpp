#include "PortManager.hpp"

namespace C418
{
    PortManager::PortManager()
    {
        // NOTE: Currently does nothing
    }

    PortManager::~PortManager()
    {
        // NOTE: Currnently does nothing
    }

    PortManager& PortManager::Instance()
    {
        static PortManager instance;
        return instance;
    }
}