#include "SceneBuilder.h"


void SceneBuilder::build()
{
    m_scene = std::make_shared<Scene>();
}


void SceneBuilder::buildObject(const std::shared_ptr<BaseObject> &object)
{
    m_scene->addObject(object);
}


bool SceneBuilder::isBuild() const
{
    return m_scene != nullptr;
}


std::shared_ptr<Scene> SceneBuilder::get()
{
    return m_scene;
}
