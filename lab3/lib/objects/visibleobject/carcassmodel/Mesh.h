#pragma once

#include <vector>

#include "Vertex.h"
#include "Edge.h"
#include "BaseTransformer.h"

class Mesh
{
public:
    Mesh() = default;
    Mesh(std::vector<Vertex> &vertices, std::vector<Edge> &edges);
    Mesh(std::vector<Vertex> &vertices, std::vector<Edge> &edges, Vertex &center);

    ~Mesh() = default;

    const std::vector<Vertex> &getVertices() const;
    const std::vector<Edge> &getEdges() const;
    const Vertex getOrigin() const;

    void addVertex(const Vertex &point);
    void addEdge(const Edge &edge);

    void moveVerticesToOrigin(const Vertex &center);
    void moveVerticesToCenter(const Vertex &center);
    void transformVertices(const shared_ptr<BaseTransformer> &transformer);
    void transform(const shared_ptr<BaseTransformer> &transformer, const Vertex &center);

private:
    void updateOrigin();
    Vertex m_origin;

    std::vector<Vertex> m_vertices;
    std::vector<Edge> m_edges;
};
