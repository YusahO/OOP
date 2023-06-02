#include "BaseAction.h"

void BaseAction::setManagers(std::shared_ptr<DrawManager> draw_manager,
                             std::shared_ptr<LoadManager> load_manager,
                             std::shared_ptr<SceneManager> scene_manager,
                             std::shared_ptr<TransformManager> transform_manager,
                             std::shared_ptr<ModelLoadModerator> model_load_moderator,
                             std::shared_ptr<SceneLoadModerator> scene_load_moderator,
                             std::shared_ptr<DrawCompositeAdapter> draw_composite_adapter)
{
    m_draw_manager = draw_manager;
    m_load_manager = load_manager;
    m_scene_manager = scene_manager;
    m_transform_manager = transform_manager;
    m_model_load_moderator = model_load_moderator;
    m_scene_load_moderator = scene_load_moderator;
    m_draw_composite_adapter = draw_composite_adapter;
}
