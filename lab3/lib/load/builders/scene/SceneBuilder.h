#pragma once

#include "BaseSceneBuilder.h"

class SceneBuilder : public BaseSceneBuilder
{
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

    void build() override;
    void buildObject(const std::shared_ptr<BaseObject> &object) override;
    bool isBuild() const override;

    std::shared_ptr<Scene> get() override;

private:
    std::shared_ptr<Scene> m_scene;
};
