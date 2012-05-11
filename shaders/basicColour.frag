#version 330

smooth in vec4 vertexColor;
out vec4 outputColor;
uniform float time;

const vec4 firstColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
const vec4 secondColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);

void main()
{
    float fragLoopDuration = 2.0;
    float currTime = mod(time, fragLoopDuration);
    float currLerp = currTime / fragLoopDuration;
    outputColor = mix(firstColor, vertexColor, currLerp);
}

