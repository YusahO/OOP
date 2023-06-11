#pragma once

#include "Composite.h"
#include "Camera.h"
#include "Vertex.h"

class BaseObject;

using Iterator = std::vector<std::shared_ptr<BaseObject>>::iterator;

class Scene
{
public:
    Scene();
    ~Scene() = default;

    std::size_t addObject(const std::shared_ptr<BaseObject> &object);
    std::size_t addCamera(const Vertex &location, const Vertex &direction);
    void deleteObject(Iterator &iter);

    Iterator getObjectIter(const std::size_t id);
    std::shared_ptr<BaseObject> getObject(const std::size_t id);
    std::shared_ptr<BaseObject> getObjects();
    // std::shared_ptr<BaseObject> getInvisibleObjects();

    // Iterator vbegin();
    // Iterator vend();

    Iterator begin();
    Iterator end();

    // Iterator ibegin();
    // Iterator iend();

protected:
    // std::shared_ptr<BaseObject> m_visible_objects;
    // std::shared_ptr<BaseObject> m_invisible_objects;
    std::shared_ptr<BaseObject> m_objects;
};

