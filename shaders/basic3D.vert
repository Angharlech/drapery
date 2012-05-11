#version 330

layout(location = 0) in vec3 position;

smooth out vec4 vertexColor;

uniform float time;
uniform mat4 perspectiveTransform;


void main()
{
    vec4 totalOffset = vec4(cos(time), sin(time), -20.0, 0.0);
    vec4 pos = vec4(position,1.0);
    vec4 cameraPos = pos + totalOffset;
    gl_Position = perspectiveTransform*cameraPos;
    vertexColor = vec4(1.0,1.0,1.0,1.0);
}
