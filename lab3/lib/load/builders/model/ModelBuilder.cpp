#include "ModelBuilder.h"

void ModelBuilder::build()
{
    m_model = std::make_shared<Mesh>();
}


void ModelBuilder::buildVertex(const Vertex &point)
{
    if (!isBuild()) { }

    m_model->addVertex(point);
}


void ModelBuilder::buildEdge(const Edge &edge)
{
    if (!isBuild()) { }

    m_model->addEdge(edge);
}


bool ModelBuilder::isBuild() const
{
    return m_model != nullptr;
}

std::shared_ptr<CarcassModel> ModelBuilder::get()
{
    return std::make_shared<CarcassModel>(m_model);
}
