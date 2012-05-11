#include "Map.hpp"
#include "importers.hpp"


Map::Map()
{

}

void Map::read(std::string& filename)
{
    m_objects.push_back( loadCollada(filename) );
}


Map::~Map()
{

}
