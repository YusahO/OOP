#include "LoadModelDirector.h"
#include "Exceptions.h"
#include "ModelBuilder.h"


LoadModelDirector::LoadModelDirector()
{
    m_loader = std::make_shared<FileCarcassModelLoader>();
}

LoadModelDirector::LoadModelDirector(std::shared_ptr<FileCarcassModelLoader> &loader)
{
    m_loader = loader;
}

std::shared_ptr<CarcassModel> LoadModelDirector::load(std::shared_ptr<BaseModelBuilder> builder, std::string &filename)
{
    m_loader->open(filename);

    builder->build();

    vector<Vertex> points = m_loader->loadVertices();
    int pts_amount = points.size();

    std::vector<Edge> edges = m_loader->loadEdges(pts_amount);
    int edges_amount = edges.size();

    for (int i = 0; i < pts_amount; ++i)
        builder->buildVertex(points[i]);

    for (int i = 0; i < edges_amount; ++i)
        builder->buildEdge(edges[i]);

    m_loader->close();

    return builder->get();
}
