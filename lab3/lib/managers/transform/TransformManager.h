#pragma once

#include "BaseManager.h"
#include "BaseObject.h"
#include "BaseTransformer.h"

class TransformManager : public BaseManager
{
public:
    TransformManager() = default;
    TransformManager(const TransformManager &manager) = delete;
    TransformManager &operator = (const TransformManager &manager) = delete;

    ~TransformManager() = default;

    void translateObject(const std::shared_ptr<BaseObject> &object,
        const double &dx,
        const double &dy,
        const double &dz);

    void scaleObject(const std::shared_ptr<BaseObject> &object,
        const double &kx,
        const double &ky,
        const double &kz);
        
    void rotateObject(const std::shared_ptr<BaseObject> &object,
        const double &ox,
        const double &oy,
        const double &oz);

    void transformObject(const std::shared_ptr<BaseObject> &object, std::shared_ptr<BaseTransformer> &transformer);
};

