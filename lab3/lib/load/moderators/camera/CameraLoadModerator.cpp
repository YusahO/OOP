#include "CameraLoadModerator.h"
#include "Exceptions.h"
#include "CameraBuilder.h"


CameraLoadModerator::CameraLoadModerator(std::shared_ptr<BaseCameraDirector> director) :
    m_builder(new CameraBuilder)
{
    m_director = director;
}

std::shared_ptr<BaseObject> CameraLoadModerator::load(std::string &filename)
{
    std::shared_ptr<Camera> camera_sh_ptr;

    try
    {
        camera_sh_ptr = m_director->load(m_builder, filename);
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

    return std::shared_ptr<BaseObject>(camera_sh_ptr);
}
