#include "LoadManager.h"

#include <QDebug>

std::shared_ptr<BaseObject> LoadManager::load(std::string &name)
{
    return m_moderator->load(name);
}

std::shared_ptr<Scene> LoadManager::loadScene(std::string &name)
{
    return m_scene_moderator->load(name);
}

void LoadManager::setModerator(std::shared_ptr<BaseLoadModerator> moderator)
{
    m_moderator = moderator;
}

void LoadManager::setSceneModerator(std::shared_ptr<SceneLoadModerator> moderator)
{
    m_scene_moderator = moderator;
}
