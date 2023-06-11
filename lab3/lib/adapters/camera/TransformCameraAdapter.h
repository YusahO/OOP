#pragma once

#include "CameraAdapter.h"
#include "BaseTransformer.h"

class TransformCameraAdapter : public CameraAdapter
{
public:
    void setTransformer(const std::shared_ptr<BaseTransformer> &transformer);
    void setOrigin(const Vertex &origin);

    virtual void request() override;

private:
    std::shared_ptr<BaseTransformer> m_transformer;
    Vertex m_origin;
};
