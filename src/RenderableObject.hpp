#pragma once
#include <vector>
#include <iostream>

class RenderableObject
{
    public:
        RenderableObject(std::vector<float>const& vertices):m_vertices(vertices){}
        ~RenderableObject(){}
        RenderableObject(const RenderableObject& o){std::cout << "RENDERABLEOBJECT copy!!!" << std::endl;}
        std::vector<float> getVertexVector(){return m_vertices;}
        void print(){std::cout << "my first vertex is " << m_vertices[0] << std::endl;}
        void render();

    private:
        std::vector<float>  m_vertices;
};


