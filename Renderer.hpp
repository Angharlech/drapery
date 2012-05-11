
#ifndef RENDERER
#define RENDERER

#include <boost/function.hpp>

class Renderer
{
    public:
        Renderer();
        ~Renderer();

        boost::function<void()> onRenderComplete;
        void update();
};

#endif

