#include "TransformCompositeAdapter.h"
#include "TransformCarcassModelAdapter.h"

void TransformCompositeAdapter::setTransformer(const std::shared_ptr<BaseTransformer> &transformer)
{
    m_transformer = transformer;
}

void TransformCompositeAdapter::setOrigin(const Vertex &origin)
{
    m_origin = origin;
}

void TransformCompositeAdapter::request()
{
    moveElemsToOrigin(m_origin);
    transformElems(m_transformer);
    moveElemsToCenter(m_origin);
}

void TransformCompositeAdapter::moveElemsToOrigin(const Vertex &center)
{
    Vertex diff = Vertex(0) - center;

    std::shared_ptr<Transformer> transformer = std::make_shared<Transformer>();
    transformer->setTranslationMatrix(diff.getX(), diff.getY(), diff.getZ());
    transformElems(transformer);
    m_adaptee->updateOrigin();
}

void TransformCompositeAdapter::moveElemsToCenter(const Vertex &center)
{
    Vertex diff = center - m_origin;

    std::shared_ptr<Transformer> transformer = std::make_shared<Transformer>();;
    transformer->setTranslationMatrix(diff.getX(), diff.getY(), diff.getZ());
    transformElems(transformer);

    m_adaptee->updateOrigin();
}

void TransformCompositeAdapter::transformElems(const std::shared_ptr<BaseTransformer> &transformer)
{
    for (const auto &elem : m_adaptee->m_elements)
    {
        if (elem->isComposite())
        {
            auto adapter = TransformCompositeAdapter();
            adapter.setTransformer(m_transformer);
            adapter.setAdaptee(std::dynamic_pointer_cast<Composite>(elem));
            adapter.setOrigin(elem->getOrigin());

            adapter.request();
        }
        else
        {
            auto adapter = TransformCarcassModelAdapter();
            adapter.setTransformer(m_transformer);
            adapter.setAdaptee(std::dynamic_pointer_cast<CarcassModel>(elem));
            adapter.setOrigin(elem->getOrigin());

            adapter.request();
        }
    }
}