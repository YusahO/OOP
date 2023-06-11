#include <CarcassModel.h>

CarcassModel::CarcassModel(const std::shared_ptr<Mesh> &model_structure)
    : m_mesh(model_structure)
{
}

CarcassModel::CarcassModel()
    : m_mesh(new Mesh)
{
}

CarcassModel::CarcassModel(const CarcassModel &model)
{
    m_mesh = model.m_mesh;
    m_id = model.m_id;
}

Vertex CarcassModel::getOrigin() const
{
    return m_mesh->getOrigin();
}