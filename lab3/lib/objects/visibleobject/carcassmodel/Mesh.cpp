#include "Mesh.h"
#include "Transformer.h"

Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<Edge> &edges)
    : m_origin { },
      m_vertices(vertices),
      m_edges(edges)
{
}


Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<Edge> &edges, Vertex &center)
    : m_origin(center),
      m_vertices(vertices),
      m_edges(edges)
{
}

const std::vector<Vertex> &Mesh::getVertices() const
{
    return m_vertices;
}

const std::vector<Edge> &Mesh::getEdges() const
{
    return m_edges;
}

const Vertex Mesh::getOrigin() const
{
    return m_origin;
}

void Mesh::addVertex(const Vertex &point)
{
    m_vertices.emplace_back(point);
    updateOrigin();
}

void Mesh::addEdge(const Edge &edge)
{
    m_edges.emplace_back(edge);
}

void Mesh::updateOrigin()
{
    m_origin = Vertex(0);

    for (const auto &element : m_vertices)
        m_origin = m_origin + element.getOrigin();

    size_t count = m_vertices.size();
    m_origin = Vertex(
        m_origin.getX() / count,
        m_origin.getY() / count,
        m_origin.getZ() / count
    );
}

void Mesh::moveVerticesToOrigin(const Vertex &center)
{
    Vertex diff = Vertex(0) - center;

    std::shared_ptr<Transformer> transformer = std::make_shared<Transformer>();
    transformer->setTranslationMatrix(diff.getX(),  diff.getY(),  diff.getZ());

    transformVertices(transformer);
    updateOrigin();
}

void Mesh::moveVerticesToCenter(const Vertex &center)
{
    Vertex diff = center - Vertex(0);

    std::shared_ptr<Transformer> transformer = std::make_shared<Transformer>();
    transformer->setTranslationMatrix(diff.getX(),  diff.getY(),  diff.getZ());

    transformVertices(transformer);
    updateOrigin();
}

void Mesh::transformVertices(const shared_ptr<BaseTransformer> &transformer)
{
    for (auto &vertex : m_vertices)
        transformer->transform(vertex);
}

void Mesh::transform(const shared_ptr<BaseTransformer> &transformer, const Vertex &center)
{
    moveVerticesToOrigin(center);
    transformVertices(transformer);
    moveVerticesToCenter(center);
    updateOrigin();
}
