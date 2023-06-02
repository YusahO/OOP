#pragma once

#include "BaseSceneDirector.h"
#include "SceneBuilder.h"

class SceneLoadModerator
{
public:
    SceneLoadModerator() = default;
    explicit SceneLoadModerator(std::shared_ptr<BaseSceneDirector> director);

    ~SceneLoadModerator() = default;

    std::shared_ptr<Scene> load(std::string &filename);
    virtual void setDirector(std::shared_ptr<BaseSceneDirector> director);

private:
    std::shared_ptr<SceneBuilder> m_builder;
    std::shared_ptr<BaseSceneDirector> m_director;
};
