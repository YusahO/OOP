#include "Facade.h"

Facade::Facade()
{
    m_draw_manager = ManagerSolution<DrawManagerCreator>().create();
    m_load_manager = ManagerSolution<LoadManagerCreator>().create();
    m_scene_manager = ManagerSolution<SceneManagerCreator>().create();
    m_transform_manager = ManagerSolution<TransformManagerCreator>().create();
    m_model_load_moderator = ModeratorSolution<ModelLoadModeratorCreator>().create();
    m_scene_load_moderator = ModeratorSolution<SceneLoadModeratorCreator>().create();;
    m_draw_composite_adapter = std::make_shared<DrawCompositeAdapter>();

    m_load_manager->setModerator(m_model_load_moderator);
    m_load_manager->setSceneModerator(m_scene_load_moderator);
    m_draw_manager->setAdapter(m_draw_composite_adapter);
}

void Facade::execute(BaseAction &command)
{
    command.setManagers(
        m_draw_manager,
        m_load_manager,
        m_scene_manager,
        m_transform_manager,
        m_model_load_moderator,
        m_scene_load_moderator,
        m_draw_composite_adapter
    );

    qDebug() << "get cam" << (void *)m_scene_manager->getCamera().get();
    m_draw_manager->setCamera(m_scene_manager->getCamera());
    command.execute();
}
