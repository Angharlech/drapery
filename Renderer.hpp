#ifndef RENDERER
#define RENDERER

#include <utility>
#include <boost/function.hpp>
#include "ShaderProgram.hpp"

class Renderer
{
    public:
        Renderer();
        ~Renderer();

        boost::function<void()> onRenderComplete;
        void update();
    private:
        void initialiseShaders();
        std::unique_ptr<ShaderProgram> m_shaderProgram;
};

#endif

