#include <iterator>

#include "Scene.h"
#include "Composite.h"

#include <QDebug>

Scene::Scene()
    : m_objects(new Composite)
{
}

std::size_t Scene::addObject(const std::shared_ptr<BaseObject> &object)
{
    // if (object->isVisible())
    //     m_visible_objects->add(object);
    // else
    //     m_invisible_objects->add(object);
    m_objects->add(object);
    return object->getId();
}

std::size_t Scene::addCamera(const Vertex &location, const Vertex &direction)
{
    auto camera = std::make_shared<Camera>(location, direction);
    // m_invisible_objects->add(camera);
    m_objects->add(camera);

    return camera->getId();
}

void Scene::deleteObject(Iterator &iter)
{
    // if ((*iter)->isVisible())
    //     m_visible_objects->remove(iter);
    // else
    //     m_invisible_objects->remove(iter);
    m_objects->remove(iter);
}

Iterator Scene::getObjectIter(const std::size_t id)
{
    auto iter = begin();
    // qDebug() << (void *)iter->get();
    for (; iter != end() && (*iter)->getId() != id; ++iter);

    // if (iter == end())
    // {
    //     iter = begin();
    //     for (; iter != end() && (*iter)->getId() != id; ++iter);
    // }

    return iter;
}

std::shared_ptr<BaseObject> Scene::getObject(const std::size_t id)
{
    return *getObjectIter(id);
}

// std::shared_ptr<BaseObject> Scene::getVisibleObjects()
// {
//     return m_objects;
// }

std::shared_ptr<BaseObject> Scene::getObjects()
{
    return m_objects;
}

// Iterator Scene::begin()
// {
//     return m_objects->begin();
// }

// Iterator Scene::end()
// {
//     return m_objects->end();
// }

Iterator Scene::begin()
{
    return m_objects->begin();
}

Iterator Scene::end()
{
    return m_objects->end();
}

// Iterator Scene::begin()
// {
//     return m_objects->begin();
// }

// Iterator Scene::end()
// {
//     return m_objects->end();
// }
