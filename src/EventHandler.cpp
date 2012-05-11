#include <iostream>
#include "EventHandler.hpp"

#include <SDL/SDL.h>


EventHandler::EventHandler()
{

}

EventHandler::~EventHandler()
{

}

void EventHandler::processEvents()
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
    }
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
