#include "SceneAction.h"

ClearScene::ClearScene(std::shared_ptr<BaseDrawer> drawer) : m_drawer(drawer)
{
    m_method = &DrawManager::clearScene;
}

void ClearScene::execute()
{
    (*(m_draw_manager).*m_method)(m_drawer);
}



GetMainCamera::GetMainCamera(std::shared_ptr<Camera> &camera)
    : m_camera(camera)
{
    m_method = &SceneManager::getCamera;
}

void GetMainCamera::execute()
{
    m_camera = (*(m_scene_manager).*m_method)();
}



GetSceneObjects::GetSceneObjects(std::shared_ptr<BaseObject> &objects)
    : m_objects(objects)
{
    m_method = &SceneManager::getObjects;
}

void GetSceneObjects::execute()
{
    m_objects = ((*m_scene_manager).*m_method)();
}



GetSceneObject::GetSceneObject(std::shared_ptr<BaseObject> &object, const std::size_t id) : m_object(object), m_id(id)
{
    m_method = &SceneManager::getObject;
}

void GetSceneObject::execute()
{
    m_object = ((*m_scene_manager).*m_method)(m_id);
}



DrawScene::DrawScene(std::shared_ptr<Scene> scene, std::shared_ptr<BaseDrawer> drawer) : m_scene(scene), m_drawer(drawer)
{
    m_method = &DrawManager::drawScene;
}

void DrawScene::execute()
{
    ((*m_draw_manager).*m_method)(m_scene, m_drawer);
}



SetScene::SetScene(std::shared_ptr<Scene> scene) : m_scene(scene)
{
    m_method = &SceneManager::setScene;
}

void SetScene::execute()
{
    ((*m_scene_manager).*m_method)(m_scene);
}



GetScene::GetScene(std::shared_ptr<Scene> &scene) : m_scene(scene)
{
    m_method = &SceneManager::getScene;
}

void GetScene::execute()
{
    m_scene = ((*m_scene_manager).*m_method)();
}



LoadScene::LoadScene(std::shared_ptr<Scene> &scene, const std::string fileName) : m_scene(scene), m_fileName(fileName)
{
    m_method = &LoadManager::loadScene;
}

void LoadScene::execute()
{
    m_scene = ((*m_load_manager).*m_method)(m_fileName);
}
