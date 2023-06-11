#include <utility>
#include "SceneManager.h"


SceneManager::SceneManager()
{
    m_scene = std::make_shared<Scene>();
}


std::shared_ptr<Scene> SceneManager::getScene() const
{
    return m_scene;
}


std::shared_ptr<Camera> SceneManager::getCamera() const
{
    return m_camera;
}

std::shared_ptr<BaseObject> SceneManager::getObject(const size_t id)
{
    return m_scene->getObject(id);
}

std::shared_ptr<BaseObject> SceneManager::getObjects()
{
    return m_scene->getObjects();
}

size_t SceneManager::addCamera(const Vertex &location, const Vertex &direction)
{
    return m_scene->addCamera(location, direction);
}

size_t SceneManager::addObject(const shared_ptr<BaseObject> &object)
{
    return m_scene->addObject(object);
}

void SceneManager::retranslateObject(const size_t id)
{
    Iterator object_iter = m_scene->getObjectIter(id);
    m_scene->deleteObject(object_iter);
}


void SceneManager::setScene(std::shared_ptr<Scene> &scene)
{
    m_scene = std::move(scene);
}


void SceneManager::setCamera(const std::size_t id)
{
    m_camera = std::dynamic_pointer_cast<Camera>(*m_scene->getObjectIter(id));
    qDebug() << (void*)m_camera.get();
}
