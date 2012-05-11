#include <GL/glew.h>
#include "ShaderProgram.hpp"

GLuint ShaderProgram::compile(GLuint type, const std::string &source) 
{
    GLuint shader = glCreateShader(type);
    const char* strSource = source.c_str();
    glShaderSource(shader, N, &strSource, NULL);
    glCompileShader(shader);
    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled)
    {
        GLint length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        std::string log(length, ' ');
        glGetShaderInfoLog(shader, length, &length, &log[0]);
        throw std::logic_error(log);
        return false;
    }

    return shader;
}

ShaderProgram::ShaderProgram(std::string& v_source, std::string& f_source)
{
    m_vertexShader = compile(GL_VERTEX_SHADER, v_source);
    m_fragmentShader = compile(GL_FRAGMENT_SHADER, f_source);
    m_prog = glCreateProgram();
    glAttachShader(m_prog, m_vertexShader);
    glAttachShader(m_prog, m_fragmentShader);
    glLinkProgram(m_prog);
}

operator ShaderProgram::GLuint() 
{ 
    return m_prog; 
}

void operator ShaderProgram::()() 
{ 
    glUseProgram(m_prog); 
}

ShaderProgram::~ShaderProgram() 
{
    glDeleteProgram(m_prog);
    glDeleteShader(m_vertexShader);
    glDeleteShader(m_fragmentShader);
}
