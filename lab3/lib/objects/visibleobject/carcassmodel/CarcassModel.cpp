#include <CarcassModel.h>

CarcassModel::CarcassModel(const std::shared_ptr<Mesh> &model_structure)
    : m_data(model_structure)
{
}

CarcassModel::CarcassModel()
    : m_data(new Mesh)
{
}

CarcassModel::CarcassModel(const CarcassModel &model)
{
    m_data = model.m_data;
    m_id = model.m_id;
}

Vertex CarcassModel::getCenter() const
{
    return m_data->getCenter();
}

void CarcassModel::transform(const Matrix<double> &mat, const Vertex &center)
{
    m_data->transform(mat, center);
}
