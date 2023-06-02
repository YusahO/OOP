#pragma once

#include <memory>

#include "BaseAction.h"

#include "ManagerSolution.h"
#include "DrawManagerCreator.h"
#include "SceneManagerCreator.h"
#include "TransformManagerCreator.h"
#include "LoadManagerCreator.h"

#include "ModeratorSolution.h"
#include "ModelLoadModeratorCreator.h"
#include "SceneLoadModeratorCreator.h"

class Facade
{
public:
    Facade();
    ~Facade() = default;

    void execute(BaseAction &command);
private:
    std::shared_ptr<DrawManager> m_draw_manager;
    std::shared_ptr<LoadManager> m_load_manager;
    std::shared_ptr<SceneManager> m_scene_manager;
    std::shared_ptr<TransformManager> m_transform_manager;
    std::shared_ptr<ModelLoadModerator> m_model_load_moderator;
    std::shared_ptr<SceneLoadModerator> m_scene_load_moderator;
    std::shared_ptr<DrawCompositeAdapter> m_draw_composite_adapter;
};

