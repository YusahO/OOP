#pragma once

#include "CompositeAdapter.h"
#include "Transformer.h"

class TransformCompositeAdapter : public CompositeAdapter
{
public:
    void setTransformer(const std::shared_ptr<BaseTransformer> &transformer);
    void setOrigin(const Vertex &origin);

    virtual void request() override;

private:
    virtual void moveElemsToOrigin(const Vertex &center);
    virtual void moveElemsToCenter(const Vertex &center);
    virtual void transformElems(const std::shared_ptr<BaseTransformer> &transformer);

private:
    std::shared_ptr<BaseTransformer> m_transformer;
    Vertex m_origin;
};
