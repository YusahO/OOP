#pragma once


#include "BaseSceneDirector.h"
#include "FileCarcassModelLoader.h"

class FileSceneDirector : public BaseSceneDirector
{
public:
    FileSceneDirector();
    explicit FileSceneDirector(std::shared_ptr<FileCarcassModelLoader> &loader);
    ~FileSceneDirector() = default;

    std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder, std::string &filename) override;

protected:
    virtual void loadModels(std::shared_ptr<SceneBuilder> builder, std::string &filename) override;
    virtual void loadCameras(std::shared_ptr<SceneBuilder> builder, std::string &filename) override;

    std::shared_ptr<FileCarcassModelLoader> m_loader;
};
