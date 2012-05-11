#include "Renderer.hpp"

#include <GL/glew.h>

Renderer::Renderer()
{
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        //error!
    }
}

Renderer::~Renderer()
{


}

void Renderer::update()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(400.0, 160.0);
    glVertex2f(320.0, 440.0);
    glVertex2f(480.0, 440.0);
    glEnd();
    onRenderComplete();
}

