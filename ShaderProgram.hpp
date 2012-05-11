// originally derived from stackoverflow question 2795044
// Usage:
// void draw() { 
    // static shader_prog wall_shader("wall_vertex", "wall_frag");
    // static shader_prog skin_shader("skin_vertex", "skin_frag");

    // wall_shader();
    // draw_walls();

    // skin_shader();
    // draw_skin();
// }
// 
#include <GL/glew.h>

class ShaderProgram
{
    private:
        
        GLuint m_vertexShader;
        GLuint m_fragmentShader;
        GLuint m_program;

        GLuint compile(std::string & source);

    public:

        ShaderProgram(std::string& v_source, std::string& f_source);
        ~ShaderProgram();
        operator GLuint();
        void operator()();
};
