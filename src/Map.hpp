#pragma once
#include "RenderableObject.hpp"
#include <memory>


class Map
{
    public:
        Map();
        void read(std::string& filename);
        std::vector< std::unique_ptr<RenderableObject> >& getRenderableObjects(){return m_objects;}
        ~Map();

    private:
        std::vector< std::unique_ptr<RenderableObject> > m_objects;
};

