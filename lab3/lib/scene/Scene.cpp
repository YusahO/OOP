#include <iterator>

#include "Scene.h"
#include "Composite.h"

#include <QDebug>

Scene::Scene()
    : m_visible_objects(new Composite), 
      m_invisible_objects(new Composite)
{
}

std::size_t Scene::addObject(const std::shared_ptr<BaseObject> &object)
{
    if (object->isVisible())
        m_visible_objects->add(object);
    else
        m_invisible_objects->add(object);

    return object->getId();
}

std::size_t Scene::addCamera(const Vertex &location, const Vertex &direction)
{
    auto camera = std::make_shared<Camera>(Camera(location, direction));
    m_invisible_objects->add(camera);

    return camera->getId();
}

void Scene::deleteObject(Iterator &iter)
{
    if ((*iter)->isVisible())
        m_visible_objects->remove(iter);
    else
        m_invisible_objects->remove(iter);
}

Iterator Scene::getObjectIter(const std::size_t id)
{
    auto iter = vbegin();
    for (; iter != vend() && (*iter)->getId() != id; ++iter);

    if (iter == vend())
    {
        iter = ibegin();
        for (; iter != iend() && (*iter)->getId() != id; ++iter);
    }

    return iter;
}

std::shared_ptr<BaseObject> Scene::getObject(const std::size_t id)
{
    return *getObjectIter(id);
}

std::shared_ptr<Composite> Scene::getVisibleObjects()
{
    return m_visible_objects;
}

std::shared_ptr<Composite> Scene::getInvisibleObjects()
{
    return m_invisible_objects;
}

Iterator Scene::vbegin()
{
    return m_visible_objects->begin();
}

Iterator Scene::vend()
{
    return m_visible_objects->end();
}

Iterator Scene::ibegin()
{
    return m_invisible_objects->begin();
}

Iterator Scene::iend()
{
    return m_invisible_objects->end();
}
