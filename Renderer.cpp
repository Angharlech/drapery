#include "Renderer.hpp"

#include <GL/glew.h>

const std::string strVertexShader("basic2D.vert");
const std::string strFragmentShader("basicColour.frag");

const float vertexData[] = {
     0.0f,    0.5f, 0.0f, 1.0f,
     0.5f, -0.366f, 0.0f, 1.0f,
    -0.5f, -0.366f, 0.0f, 1.0f,
     1.0f,    0.0f, 0.0f, 1.0f,
     0.0f,    1.0f, 0.0f, 1.0f,
     0.0f,    0.0f, 1.0f, 1.0f,
};

GLuint positionBufferObject;
GLuint vao;


Renderer::Renderer()
{
    GLenum returnCode = glewInit();
    if ( returnCode != GLEW_OK)
    {
        //error!
    }
    
    glGenBuffers(1, &positionBufferObject); //create a buffer object, store in global variable
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject); //bind to context (?)
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW); //alloc some memory of sizeof(vertexData) then copy in vertexData
    glBindBuffer(GL_ARRAY_BUFFER, 0); //usually best to unbind what you bind as a cleanup
    initialiseShaders(); // my function
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

Renderer::~Renderer()
{


}

void Renderer::initialiseShaders()
{
    m_shaderProgram.reset(new ShaderProgram(strVertexShader, strFragmentShader));
}

void Renderer::update()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //set the colour that a clear will paint
    glClear(GL_COLOR_BUFFER_BIT); //clear the color buffer to above

    glUseProgram(*m_shaderProgram);

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);  //rebind our vertex array
    glEnableVertexAttribArray(0); //enable location 0 of vertex shader input
    glEnableVertexAttribArray(1); //enable location 1 of vertex shader input
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0); //position input
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)48); //color input

    glDrawArrays(GL_TRIANGLES, 0, 3); //draw the triangle(s) start index, num of entries

    glDisableVertexAttribArray(0); //clean up
    glUseProgram(0); //clean up

    onRenderComplete();

}
