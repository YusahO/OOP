#include "FileCarcassModelLoader.h"
#include "Exceptions.h"
#include <source_location>

FileCarcassModelLoader::FileCarcassModelLoader()
{
    m_file = std::make_shared<std::ifstream>();
}

FileCarcassModelLoader::FileCarcassModelLoader(std::shared_ptr<std::ifstream> &file)
{
    m_file = file;
}

void FileCarcassModelLoader::open(std::string &fileName)
{
    if (!m_file)
    {
        auto loc = std::source_location::current();
        throw SourceException(loc.file_name(), loc.function_name(), loc.line(), "File not open error");
    }

    m_file->open(fileName);

    if (!m_file)
    {
        auto loc = std::source_location::current();
        throw SourceException(loc.file_name(), loc.function_name(), loc.line(), "File not open error");
    }
}

void FileCarcassModelLoader::close()
{
    if (!m_file)
    {
        auto loc = std::source_location::current();
        throw SourceException(loc.file_name(), loc.function_name(), loc.line(), "File not open error");
    }

    m_file->close();
}

std::size_t FileCarcassModelLoader::loadCount()
{
    int count;

    *m_file >> count;

    return count;
}

Vertex FileCarcassModelLoader::loadVertex()
{
    double x, y, z;

    *m_file >> x >> y >> z;

    return Vertex(x, y, z);
}

std::vector<Vertex> FileCarcassModelLoader::loadVertices()
{
    std::vector<Vertex> vertexes;

    int vertexNum;
    *m_file >> vertexNum;

    if (vertexNum <= 0)
    {
        auto loc = std::source_location::current();
        throw SourceException(loc.file_name(), loc.function_name(), loc.line(), "Wrong vertex number error");
    }

    double x, y, z;

    for (int i = 0; i < vertexNum; i++)
    {
       *m_file >> x >> y >> z;
       vertexes.push_back(Vertex(x, y, z));
    }

    return vertexes;
}

std::vector<Edge> FileCarcassModelLoader::loadEdges(int &vertex_amount)
{
    std::vector<Edge> links;

    int links_amount;
    *m_file >> links_amount;

    if (links_amount <= 0)
    {
        auto loc = std::source_location::current();
        throw SourceException(loc.file_name(), loc.function_name(), loc.line(), "Wrong links amount error");
    }

    int ivertex_start, ivertex_end;

    for (int i = 0; i < links_amount; i++)
    {
        *m_file >> ivertex_start >> ivertex_end;

        if (ivertex_start <= 0 or ivertex_end <= 0 or
            ivertex_start > vertex_amount or ivertex_end > vertex_amount)
        {
        auto loc = std::source_location::current();
        throw SourceException(loc.file_name(), loc.function_name(), loc.line(), "Wrong link data error");
        }

        links.emplace_back(ivertex_start, ivertex_end);
    }

    return links;
}
