#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 colorIn;

smooth out vec4 vertexColor;

uniform float time;
uniform mat4 perspectiveTransform;


void main()
{
    vec4 totalOffset = vec4(cos(time), sin(time), 0.0, 0.0);
    vec4 cameraPos = position + totalOffset;
    gl_Position = perspectiveTransform*cameraPos;
    vertexColor = colorIn;
}
