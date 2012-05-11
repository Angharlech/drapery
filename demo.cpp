#include <SDL/SDL.h>
#include <boost/bind.hpp>

#include "DisplayDevice.hpp"
#include "EventHandler.hpp"
#include "Renderer.hpp"

int main(int argc, char *argv[]) 
{

    bool fullscreen = false;
    int width = 800;
    int height = 600;
    
    DisplayDevice display(width, height, fullscreen);
    EventHandler eventHandler;
    Renderer renderer;

    //connect up the components
    eventHandler.onPollEvent = boost::bind(&Renderer::update, &renderer);
    renderer.onRenderComplete = boost::bind(swapBuffers);
    eventHandler.onKeyF12 = boost::bind(&DisplayDevice::toggleFullscreen, &display);
    eventHandler.onKeyQ = boost::bind(&EventHandler::exit, &eventHandler);
    eventHandler.onSDLQuit = boost::bind(&EventHandler::exit, &eventHandler);
    eventHandler.onKeyReturn = boost::bind(&EventHandler::exit, &eventHandler);
    eventHandler.start();

    return 0;
}

