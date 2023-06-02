
#pragma once

#include "DrawManager.h"
#include "LoadManager.h"
#include "SceneManager.h"
#include "TransformManager.h"
#include "CameraLoadModerator.h"
#include "ModelLoadModerator.h"
#include "SceneLoadModerator.h"
#include "DrawCompositeAdapter.h"

class BaseAction
{
public:
    BaseAction() = default;
    virtual ~BaseAction() = default;

    virtual void setManagers(std::shared_ptr<DrawManager> draw_manager,
                             std::shared_ptr<LoadManager> load_manager,
                             std::shared_ptr<SceneManager> scene_manager,
                             std::shared_ptr<TransformManager> transform_manager,
                             std::shared_ptr<ModelLoadModerator> model_load_moderator,
                             std::shared_ptr<SceneLoadModerator> scene_load_moderator,
                             std::shared_ptr<DrawCompositeAdapter> draw_composite_adapter);

    virtual void execute() = 0;

protected:
    std::shared_ptr<DrawManager> m_draw_manager;
    std::shared_ptr<LoadManager> m_load_manager;
    std::shared_ptr<SceneManager> m_scene_manager;
    std::shared_ptr<TransformManager> m_transform_manager;
    std::shared_ptr<ModelLoadModerator> m_model_load_moderator;
    std::shared_ptr<SceneLoadModerator> m_scene_load_moderator;
    std::shared_ptr<DrawCompositeAdapter> m_draw_composite_adapter;
};
