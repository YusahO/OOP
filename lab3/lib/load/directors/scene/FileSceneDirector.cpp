#include "FileSceneDirector.h"
#include "FileCameraDirector.h"
#include "LoadModelDirector.h"
#include "Exceptions.h"

FileSceneDirector::FileSceneDirector()
{
    m_loader = std::make_shared<FileCarcassModelLoader>();
}

FileSceneDirector::FileSceneDirector(std::shared_ptr<FileCarcassModelLoader> &loader)
{
    m_loader = loader;
}

std::shared_ptr<Scene> FileSceneDirector::load(std::shared_ptr<SceneBuilder> builder, std::string &filename)
{
    m_loader->open(filename);

    builder->build();

    loadModels(builder, filename);
    loadCameras(builder, filename);

    m_loader->close();

    return builder->get();
}

void FileSceneDirector::loadModels(std::shared_ptr<SceneBuilder> builder, std::string &filename)
{
    size_t models_amount = m_loader->loadCount();

    auto model_builder = std::make_shared<ModelBuilder>();

    for (size_t i = 0; i < models_amount; ++i)
    {
        auto model = LoadModelDirector(m_loader).load(model_builder, filename);
        builder->buildObject(model);
    }
}

void FileSceneDirector::loadCameras(std::shared_ptr<SceneBuilder> builder, std::string &filename)
{
    size_t cameras_amount = m_loader->loadCount();

    auto camera_builder = std::make_shared<CameraBuilder>();

    for (size_t i = 0; i < cameras_amount; ++i)
    {
        auto camera = FileCameraDirector(m_loader).load(camera_builder, filename);
        builder->buildObject(camera);
    }
}
