#pragma once

#include "DisplayDevice.hpp"
#include "EventHandler.hpp"
#include "Renderer.hpp"
#include "Map.hpp"

class EngineCoordinator
{
    public:
        EngineCoordinator();
        ~EngineCoordinator();
        void loadMap(std::string& filename);
        void startMainLoop();
    private:
        bool m_running = false;
        Map m_map;
        void stopMainLoop();
};

