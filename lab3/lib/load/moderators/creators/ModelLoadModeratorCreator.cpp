#include <ModelLoadModeratorCreator.h>
#include <FileModelDirector.h>

std::shared_ptr<ModelLoadModerator> ModelLoadModeratorCreator::createModerator()
{
    if (nullptr == m_moderator)
        createInstance();

    return m_moderator;
}

void ModelLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<ModelLoadModerator> moderator;

    if (!moderator)
    {
        auto reader = std::shared_ptr<FileCarcassModelLoader>(new FileCarcassModelLoader());
        auto director = std::shared_ptr<BaseModelDirector>(new FileModelDirector(reader));
        moderator = std::make_shared<ModelLoadModerator>(director);
    }

    m_moderator = moderator;
}
