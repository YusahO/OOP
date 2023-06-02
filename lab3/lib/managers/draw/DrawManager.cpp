#include <DrawManager.h>
#include <BaseModel.h>
#include <Camera.h>

void DrawManager::setAdapter(std::shared_ptr<DrawCompositeAdapter> adapter)
{
    m_adapter = adapter;
}

void DrawManager::setCamera(std::shared_ptr<Camera> camera)
{
    m_adapter->setCamera(camera);
}

void DrawManager::clearScene(std::shared_ptr<BaseDrawer> drawer)
{
    drawer->clearScene();
}

void DrawManager::drawScene(std::shared_ptr<Scene> scene, std::shared_ptr<BaseDrawer> drawer)
{
    m_adapter->setDrawer(drawer);
    m_adapter->setAdaptee(scene->getVisibleObjects());
    m_adapter->request();
}
