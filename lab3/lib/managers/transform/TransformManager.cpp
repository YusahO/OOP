#include <cmath>

#include "TransformManager.h"
#include "Transformer.h"
#include "TransformCarcassModelAdapter.h"
#include "TransformCameraAdapter.h"
#include "TransformCompositeAdapter.h"

void TransformManager::translateObject(const std::shared_ptr <BaseObject> &object,
    const double &dx,
    const double &dy,
    const double &dz)
{
    std::shared_ptr<Transformer> transformer = std::make_shared<Transformer>();
    transformer->setTranslationMatrix(dx, dy, dz);

    if (object->isComposite())
    {
        TransformCompositeAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<Composite>(object));
        adapter.request();
    }
    else if (!object->isComposite() && !object->isVisible())
    {
        TransformCameraAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setAdaptee(std::dynamic_pointer_cast<Camera>(object));
        adapter.setOrigin(object->getOrigin());
        adapter.request();
    }
    else if (!object->isComposite() && object->isVisible())
    {
        TransformCarcassModelAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<CarcassModel>(object));
        adapter.request();
    }
}


void TransformManager::scaleObject(const std::shared_ptr <BaseObject> &object,
    const double &kx,
    const double &ky,
    const double &kz)
{
    std::shared_ptr<Transformer> transformer = std::make_shared<Transformer>();
    transformer->setScalingMatrix(kx, ky, kz);

    if (object->isComposite())
    {
        TransformCompositeAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<Composite>(object));
        adapter.request();
    }
    else if (!object->isComposite() && !object->isVisible())
    {
        TransformCameraAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<Camera>(object));
        adapter.request();
    }
    else if (!object->isComposite() && object->isVisible())
    {
        TransformCarcassModelAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<CarcassModel>(object));
        adapter.request();
    }
}


void TransformManager::rotateObject(const std::shared_ptr <BaseObject> &object,
    const double &ax,
    const double &ay,
    const double &az)
{
    std::shared_ptr<Transformer> transformer = std::make_shared<Transformer>();
    transformer->setRotationMatrix(ax, ay, az);

    if (object->isComposite())
    {
        TransformCompositeAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<Composite>(object));
        adapter.request();
    }
    else if (!object->isComposite() && !object->isVisible())
    {
        TransformCameraAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<Camera>(object));
        adapter.request();
    }
    else if (!object->isComposite() && object->isVisible())
    {
        TransformCarcassModelAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<CarcassModel>(object));
        adapter.request();
    }
}

void TransformManager::transformObject(const std::shared_ptr<BaseObject> &object,
    std::shared_ptr<BaseTransformer> &transformer)
{
    if (object->isComposite())
    {
        TransformCompositeAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<Composite>(object));
        adapter.request();
    }
    else if (!object->isComposite() && !object->isVisible())
    {
        TransformCameraAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<Camera>(object));
        adapter.request();
    }
    else if (!object->isComposite() && object->isVisible())
    {
        TransformCarcassModelAdapter adapter;

        adapter.setTransformer(transformer);
        adapter.setOrigin(object->getOrigin());
        adapter.setAdaptee(std::dynamic_pointer_cast<CarcassModel>(object));
        adapter.request();
    }
}
