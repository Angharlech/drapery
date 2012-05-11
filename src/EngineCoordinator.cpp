#include "EngineCoordinator.hpp"
#include <boost/bind.hpp>

EngineCoordinator::EngineCoordinator()
{
}
EngineCoordinator::~EngineCoordinator()
{

}

void EngineCoordinator::loadMap(std::string& filename)
{
    m_map.read(filename);
}


void EngineCoordinator::startMainLoop()
{
    bool fullscreen = false;
    int width = 800;
    int height = 600;
    DisplayDevice display(width, height, fullscreen);
    EventHandler eventHandler;
    Renderer renderer(width, height, m_map.getRenderableObjects());
    
    eventHandler.onKeyF12 = boost::bind(&DisplayDevice::toggleFullscreen, &display);
    eventHandler.onKeyQ = boost::bind(&EngineCoordinator::stopMainLoop, this);
    eventHandler.onSDLQuit = boost::bind(&EngineCoordinator::stopMainLoop, this);
    eventHandler.onKeyReturn = boost::bind(&EngineCoordinator::stopMainLoop, this);
    display.onWindowResize = boost::bind(&Renderer::resizeView, &renderer, _1, _2);

    m_running = true;
    while (m_running) 
    {
        eventHandler.processEvents();
        renderer.update();
        display.swapBuffers();
    }

}

void EngineCoordinator::stopMainLoop()
{
    m_running = false;
}
