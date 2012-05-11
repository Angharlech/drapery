#include "DisplayDevice.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <iostream>


DisplayDevice::DisplayDevice()
{
    DisplayDevice(0,0,true);
}


DisplayDevice::DisplayDevice(int width, int height, bool fullscreen) :
    m_preferredWidth(width),
    m_preferredHeight(height)
{
    if ( SDL_Init(SDL_INIT_VIDEO)  == -1 )
    {
        //return false;
    }
    const SDL_VideoInfo* initialDisplayMode = SDL_GetVideoInfo();
    m_maximumWidth = initialDisplayMode->current_w;
    m_maximumHeight = initialDisplayMode->current_h;
    setVideoMode(width,height,fullscreen);
    SDL_WM_SetCaption("openGLDemo", NULL);
    SDL_Surface* screen = SDL_GetVideoSurface();
    glViewport(0, 0, screen->w, screen->h);
    glOrtho(0.0, (GLdouble)screen->w, (GLdouble)screen->h, 0.0, 0.0, 1.0);
    glClearColor(0,0,0,0);
}


DisplayDevice::~DisplayDevice()
{
    SDL_Quit();
}


void swapBuffers()
{
    SDL_GL_SwapBuffers();
}

void setVideoMode(int width, int height, bool fullscreen)
{
    if (fullscreen)
    {
        SDL_SetVideoMode(width, height, 32, SDL_OPENGL|SDL_FULLSCREEN);
    }
    else
    {
        SDL_SetVideoMode(width, height, 32, SDL_OPENGL);
    }
}

void DisplayDevice::toggleFullscreen()
{
    SDL_Surface* screen = SDL_GetVideoSurface();
    int width = screen->w;
    int height = screen->h;
    bool fullscreen =  screen->flags & SDL_FULLSCREEN;
    if (fullscreen)
    {
        setVideoMode(m_preferredWidth, m_preferredHeight, false);
    }
    else
    {
        setVideoMode(m_maximumWidth, m_maximumHeight, true);
    }
}

