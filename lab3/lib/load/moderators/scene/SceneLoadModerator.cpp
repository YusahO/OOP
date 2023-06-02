#include "SceneLoadModerator.h"
#include "Exceptions.h"
#include <source_location>

SceneLoadModerator::SceneLoadModerator(std::shared_ptr<BaseSceneDirector> director) :
    m_builder(new SceneBuilder)
{
    m_director = director;
}

std::shared_ptr<Scene> SceneLoadModerator::load(std::string &filename)
{
    std::shared_ptr<Scene> scene;

    try
    {
        scene = m_director->load(m_builder, filename);
    }
    catch (SourceException &error)
    {
        auto loc = std::source_location::current();
        throw SourceException(loc.file_name(), loc.function_name(), loc.line(), "File not open error");
    }
    catch (std::exception &error)
    {
        auto loc = std::source_location::current();
        throw SourceException(loc.file_name(), loc.function_name(), loc.line(), "Read model error");
    }

    return scene;
}

void SceneLoadModerator::setDirector(std::shared_ptr<BaseSceneDirector> director)
{
    m_director = director;
}
