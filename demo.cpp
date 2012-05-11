#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>


void setVideoMode(int width, int height, bool fullscreen)
{
    if (fullscreen)
    {
        SDL_SetVideoMode(0, 0, 32, SDL_OPENGL|SDL_FULLSCREEN);
    }
    else
    {
        SDL_SetVideoMode(width, height, 32, SDL_OPENGL);
    }
}

void toggleFullscreen()
{
    SDL_Surface* screen = SDL_GetVideoSurface();
    int width = screen->w;
    int height = screen->h;
    bool fullscreen =  screen->flags & SDL_FULLSCREEN;
    setVideoMode(0, 0, !fullscreen);
}

bool init_GL()
{
    SDL_Surface* screen = SDL_GetVideoSurface();
    glViewport(0, 0, screen->w, screen->h);
    glOrtho(0.0, (GLdouble)screen->w, (GLdouble)screen->h, 0.0, 0.0, 1.0);
    glClearColor(0,0,0,0);
}

bool initialiseWindow(SDL_Surface* screen, int width, int height, bool fullscreen)
{
    if ( SDL_Init(SDL_INIT_VIDEO)  == -1 )
    {
        return false;
    }
    setVideoMode(width,height,fullscreen);
    if ( init_GL() == false)
    {
        return false;
    }

    SDL_WM_SetCaption("openGLDemo", NULL);
    return true;
}

void processKeyPress(int key)
{
    switch (key)
    {
        case SDLK_UP: break;
        case SDLK_RETURN: break;
        case SDLK_F12: toggleFullscreen(); break;
        case SDLK_q: break;
    }
}

int main(int argc, char *argv[]) 
{
    SDL_Event event;
    SDL_Surface* screen;

    bool fullscreen = false;
    int width = 800;
    int height = 600;
    initialiseWindow(screen, width, height, fullscreen);

    bool quit = false;
    while (!quit) 
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            if (event.type == SDL_KEYDOWN)
            {
                processKeyPress(event.key.keysym.sym);
            }
            
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(1.0f,1.0f,1.0f);
            glBegin(GL_TRIANGLES);
                glVertex2f(400.0, 160.0);
                glVertex2f(320.0, 440.0);
                glVertex2f(480.0, 440.0);
            glEnd();
            SDL_GL_SwapBuffers();
            SDL_Delay(10);
        }
    }
    SDL_Quit();
    return 0;
}

