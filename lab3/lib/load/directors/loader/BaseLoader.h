#pragma once

#include <string>
#include <vector>

#include "Vertex.h"
#include "Edge.h"


class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(std::string &fileName) = 0;
    virtual void close() = 0;

    virtual std::size_t loadCount() = 0;
    virtual Vertex loadVertex() = 0;
    virtual std::vector<Vertex> loadVertices() = 0;
    virtual std::vector<Edge> loadEdges(int &points_amount) = 0;
};
