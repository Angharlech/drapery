#ifndef RENDERER
#define RENDERER

#include <utility>
#include <boost/function.hpp>
#include "ShaderProgram.hpp"
#include "Perspective.hpp"
#include "RenderableObject.hpp"

class Renderer
{
    public:
        Renderer(int width, int height, std::vector< std::unique_ptr<RenderableObject> >& objects);
        ~Renderer();

        boost::function<void()> onRenderComplete;
        void update();
        void resizeView(const int& width, const int& height);
    private:
        void initialiseShaders();
        std::unique_ptr<ShaderProgram> m_shaderProgram;
        int m_viewWidth;
        int m_viewHeight;
        PerspectiveTransform m_perspectiveTransform;
        std::vector< std::unique_ptr<RenderableObject> >& m_objects;
};

#endif

