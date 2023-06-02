#include <SceneLoadModeratorCreator.h>
#include <FileSceneDirector.h>

std::shared_ptr<SceneLoadModerator> SceneLoadModeratorCreator::createModerator()
{
    if (m_moderator == nullptr)
        createInstance();

    return m_moderator;
}

void SceneLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<SceneLoadModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseSceneDirector> director;
        director = std::shared_ptr<BaseSceneDirector>(new FileSceneDirector);
        moderator = std::make_shared<SceneLoadModerator>(director);
    }

    m_moderator = moderator;
}


