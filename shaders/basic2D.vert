#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 colorIn;
uniform float time;

smooth out vec4 vertexColor;

void main()
{
    vec4 totalOffset = vec4(cos(time), sin(time), 0.0, 0.0);
    gl_Position = position + totalOffset;
    vertexColor = colorIn;
}
