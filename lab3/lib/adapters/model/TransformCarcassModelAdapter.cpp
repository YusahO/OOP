
#include "TransformCarcassModelAdapter.h"

void TransformCarcassModelAdapter::setTransformer(const std::shared_ptr<BaseTransformer> &transformer)
{
    m_transformer = transformer;
}

void TransformCarcassModelAdapter::setOrigin(const Vertex &origin)
{
    m_origin = origin;
}

void TransformCarcassModelAdapter::request()
{
    if (m_adaptee && m_transformer)
    {
        m_adaptee->m_mesh->transform(m_transformer, m_origin);
    }
}
