#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 colorIn;

smooth out vec4 vertexColor;

void main()
{
    gl_Position = position;
    vertexColor = colorIn;
}
