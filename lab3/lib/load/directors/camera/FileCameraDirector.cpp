#include <FileCameraDirector.h>
#include <Exceptions.h>

FileCameraDirector::FileCameraDirector()
{
    m_loader = std::make_shared<FileCarcassModelLoader>();
}

FileCameraDirector::FileCameraDirector(std::shared_ptr<FileCarcassModelLoader> &loader)
{
    m_loader = loader;
}

std::shared_ptr<Camera> FileCameraDirector::load(std::shared_ptr<BaseCameraBuilder> builder,
                                                      std::string &fileName)
{
    m_loader->open(fileName);

    builder->build();
    Vertex location = m_loader->loadVertex();
    Vertex direction = m_loader->loadVertex();
    builder->buildLocation(location, direction);

    m_loader->close();

    return builder->get();
}
