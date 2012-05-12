#include <iostream>
#include <cmath>

#include <GL/glew.h>

#include "Renderer.hpp"
#include "timing.hpp"



const std::string strVertexShader("shaders/basic3D.vert");
const std::string strFragmentShader("shaders/basicColour.frag");

GLuint positionBufferObject;
GLuint vao;
GLuint timeLocation;

Renderer::Renderer(int width, int height, std::vector< std::unique_ptr<RenderableObject> >& objects)
    :m_viewWidth(width),
    m_viewHeight(height),
    m_objects(objects)
{
    //initialise the viewport? 
    glViewport(0, 0, width, height);
    
    //initialise perspectiveTransform
    float fFrustumScale = 1.0f; float fzNear = 0.1f; float fzFar = 100.0f;
    m_perspectiveTransform.set(fFrustumScale, fzNear, fzFar, width, height);

    //initialise all the openGL extensions    
    GLenum returnCode = glewInit();
    if ( returnCode != GLEW_OK)
    {
        //error!
    }

    glGenBuffers(1, &positionBufferObject); //create a buffer object, store in global variable
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject); //bind to context (?)
   
    const std::vector<float>& vertices = m_objects[0]->getVertexVector();
    const float* vertexPointer = &vertices[0];

    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW); //alloc some memory of sizeof(vertexData) then copy in vertexData
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertices.size(), vertexPointer, GL_STATIC_DRAW); //alloc some memory of sizeof(vertexData) then copy in vertexData
    glBindBuffer(GL_ARRAY_BUFFER, 0); //usually best to unbind what you bind as a cleanup
    initialiseShaders(); // my function
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    timeLocation = glGetUniformLocation(*m_shaderProgram, "time");
    // If you want to set uniforms once, do it here but you first have to
    // enable the program (useprogram) then disable it... they can only be set
    // while program is enabled

    GLuint perspectiveTransformLocation = glGetUniformLocation(*m_shaderProgram, "perspectiveTransform");

    //copy into vertex shader
    glUseProgram(*m_shaderProgram);
    glUniformMatrix4fv(perspectiveTransformLocation, 1, GL_FALSE, m_perspectiveTransform.data()); 
    glUseProgram(0);
    //this could be an array of matrices, the one indicates only 1 matrix!
    //GL_FALSE means row-major=false


    glEnable(GL_CULL_FACE); //enable face culling
    glCullFace(GL_BACK); //backface culling
    glFrontFace(GL_CW); // clockwise winding is front face
    glEnable(GL_DEPTH_TEST); // depth testing
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL); // less than or equal to
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //set the colour that a clear will paint
    glClearDepth(1.0f);
}

Renderer::~Renderer()
{


}

void Renderer::resizeView(const int& width, const int& height)
{
    m_viewWidth = width;
    m_viewHeight = height;
    m_perspectiveTransform.resizeView(width,height);
}

void Renderer::initialiseShaders()
{
    m_shaderProgram.reset(new ShaderProgram(strVertexShader, strFragmentShader));
}

void Renderer::update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color and depth buffers

    glUseProgram(*m_shaderProgram);
    glUniform1f(timeLocation, currentTime() ); //set values of uniform variables
    //note that uniforms set in vertex will be given to fragment if you declare
    //them
    
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);  //rebind our vertex array
    glEnableVertexAttribArray(0); //enable location 0 of vertex shader input
    //glEnableVertexAttribArray(1); //enable location 1 of vertex shader input
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //position input
    //size_t colorData = sizeof(vertexData)/2;
    //glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)colorData); //color input
    
    const std::vector<float>& vertices = m_objects[0]->getVertexVector();
    glDrawArrays(GL_POINTS, 0, vertices.size()); //draw the triangle(s) start index, num of entries

    glDisableVertexAttribArray(0); //clean up
    //glDisableVertexAttribArray(1); //clean up
    glUseProgram(0); //clean up

    //onRenderComplete();
}
