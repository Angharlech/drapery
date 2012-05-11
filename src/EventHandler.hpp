#pragma once

#include <boost/function.hpp>
#include <SDL/SDL.h>

void processKeyPress(int key);

class EventHandler
{
    public:
        EventHandler();
        ~EventHandler();
        void processEvents();

        boost::function<void()> onPollEvent;
        boost::function<void()> onKeyReturn;
        boost::function<void()> onKeyF12;
        boost::function<void()> onKeyQ;
        boost::function<void()> onSDLQuit;

    private:
        void processKeyPress(int key);
        SDL_Event m_sdlEvent;
};

