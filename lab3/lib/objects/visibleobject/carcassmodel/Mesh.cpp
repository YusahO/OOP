#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<Edge> &edges)
    : m_center{ },
      m_vertices(vertices),
      m_edges(edges)
{
}


Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<Edge> &edges, Vertex &center)
    : m_center(center), 
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

const Vertex Mesh::getCenter() const
{
    return m_center;
}

void Mesh::addVertex(const Vertex &point)
{
    m_vertices.push_back(point);
    updateCenter();
}

void Mesh::addEdge(const Edge &edge)
{
    m_edges.push_back(edge);
}

void Mesh::updateCenter()
{
    m_center = Vertex(0, 0, 0);
    size_t count = 0;

    for (const auto &element : m_vertices)
    {
        m_center = m_center + element.getCenter();
        count++;
    }

    m_center = Vertex(m_center.getX() / count,
                     m_center.getY() / count,
                     m_center.getZ() / count);
}

void Mesh::moveVerticesToOrigin(const Vertex &center)
{
    Vertex diff = Vertex(0, 0, 0) - center;

    Matrix<double> mat = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformVertices(mat);
    updateCenter();
}

void Mesh::moveVerticesToCenter(const Vertex &center)
{
    Vertex diff = center - Vertex(0, 0, 0);

    Matrix<double> mat = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformVertices(mat);
    updateCenter();
}

void Mesh::transformVertices(const Matrix<double> &mat)
{
    for (auto &vertex : m_vertices)
        vertex.transform(mat);
}

void Mesh::transform(const Matrix<double> &mat, const Vertex &center)
{
    updateCenter();

    moveVerticesToOrigin(center);
    transformVertices(mat);
    moveVerticesToCenter(center);
}
