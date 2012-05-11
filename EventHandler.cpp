#include "EventHandler.hpp"

#include <SDL/SDL.h>


EventHandler::EventHandler()
    : m_running(false)
{

}

EventHandler::~EventHandler()
{

}

void EventHandler::start()
{
    m_running = true;
    while (m_running) 
    {
        while (SDL_PollEvent(&m_sdlEvent))
        {
            if (m_sdlEvent.type == SDL_QUIT)
            {
                onSDLQuit();
            }
            if (m_sdlEvent.type == SDL_KEYDOWN)
            {
                processKeyPress(m_sdlEvent.key.keysym.sym);
            }
            onPollEvent();
            //SDL_Delay(10);
        }
    }
}

void EventHandler::exit()
{
    m_running = false;
}


void EventHandler::processKeyPress(int key)
{
    switch (key)
    {
        case SDLK_UP: break;
        case SDLK_RETURN: onKeyReturn(); break;
        case SDLK_F12: onKeyF12(); break;
        case SDLK_q: onKeyQ(); break;
    }
}
