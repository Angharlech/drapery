#include <GL/glew.h>
#include "ShaderProgram.hpp"
#include <stdexcept>
#include <fstream>
#include <streambuf>
#include <iostream>

GLuint ShaderProgram::compile(GLenum type, const std::string &filename) 
{
    //read in the shader file
    std::ifstream inFile(filename);
    if (!inFile.is_open())
    {
        std::cout << "ERROR: could not open shader file" << std::endl;
        return 0;
    }
    std::string source;
    inFile.seekg(0, std::ios::end);   
    source.reserve(inFile.tellg());
    inFile.seekg(0, std::ios::beg);
    source.assign((std::istreambuf_iterator<char>(inFile)),
                std::istreambuf_iterator<char>());


    GLuint shader = glCreateShader(type);
    const char* strSource = source.c_str();
    glShaderSource(shader, 1, &strSource, NULL);
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

ShaderProgram::ShaderProgram(const std::string& v_source,const std::string& f_source)
{
    m_vertexShader = compile(GL_VERTEX_SHADER, v_source);
    m_fragmentShader = compile(GL_FRAGMENT_SHADER, f_source);
    m_program = glCreateProgram();
    glAttachShader(m_program, m_vertexShader);
    glAttachShader(m_program, m_fragmentShader);
    glLinkProgram(m_program);
}

//void ShaderProgram::operator()() 
//{ 
//    glUseProgram(m_program); 
//}

void ShaderProgram::activate()
{
    glUseProgram(m_program);
}

ShaderProgram::~ShaderProgram() 
{
    glDeleteProgram(m_program);
    glDeleteShader(m_vertexShader);
    glDeleteShader(m_fragmentShader);
}
