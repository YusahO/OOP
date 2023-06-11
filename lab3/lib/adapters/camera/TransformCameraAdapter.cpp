#include "TransformCameraAdapter.h"

void TransformCameraAdapter::setTransformer(const std::shared_ptr<BaseTransformer> &transformer)
{
    m_transformer = transformer;
}

void TransformCameraAdapter::setOrigin(const Vertex &origin)
{
    m_origin = origin;
}

void TransformCameraAdapter::request()
{
    if (m_adaptee && m_transformer)
    {
        Vertex diff = Vertex(0) - m_origin;
        m_adaptee->m_location += diff;

        m_transformer->transform(m_adaptee->m_location);

        m_adaptee->m_location -= diff;
    }
}
