#include <SceneManagerCreator.h>

std::shared_ptr<SceneManager> SceneManagerCreator::createManager() {
    if (m_manager == nullptr)
        createInstance();

    return m_manager;
}


void SceneManagerCreator::createInstance()
{
    static std::shared_ptr<SceneManager> manager(new SceneManager());
    m_manager = manager;
}
