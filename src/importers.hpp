#pragma once
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string.hpp>

#include "RenderableObject.hpp"

#include <iostream>


std::vector<float> stringToArray(std::string& input)
{
    std::vector<std::string> stringList;
    std::vector<float> array;
    boost::split(stringList, input, boost::is_any_of(" "));
    int size = stringList.size();
    array.resize(size);
    for (int i=0; i< size; ++i)
    {
        array[i] = std::stof(stringList[i]);
    }
    return array;
}

std::unique_ptr<RenderableObject> loadCollada(const std::string &filename)
{
    using boost::property_tree::ptree;
    ptree pt;
    read_xml(filename, pt);

    std::string comments = pt.get<std::string>("COLLADA.asset.contributor.comments");
    int count = pt.get<int>("COLLADA.library_geometries.geometry.mesh.source.technique_common.accessor.<xmlattr>.count");
    int stride = pt.get<int>("COLLADA.library_geometries.geometry.mesh.source.technique_common.accessor.<xmlattr>.stride");
    std::string data = pt.get<std::string>("COLLADA.library_geometries.geometry.mesh.source.float_array");
    int size = count*stride;
    auto verts = stringToArray(data);
    std::unique_ptr<RenderableObject> obj( new RenderableObject(verts) );
    return obj;
}



