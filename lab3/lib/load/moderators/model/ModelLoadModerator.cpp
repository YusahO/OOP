#include <QDebug>

#include "ModelLoadModerator.h"
#include "Exceptions.h"
#include "ModelBuilder.h"


ModelLoadModerator::ModelLoadModerator(std::shared_ptr<BaseModelDirector> director) :
    m_builder(new ModelBuilder)
{
    m_director = director;
}


std::shared_ptr<BaseObject> ModelLoadModerator::load(std::string &filename)
{
    std::shared_ptr<CarcassModel> model_ptr;

    try
    {
        model_ptr = m_director->load(m_builder, filename);
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

    return std::shared_ptr<BaseObject>(model_ptr);
}
