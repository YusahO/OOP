#include <LoadManagerCreator.h>

std::shared_ptr<LoadManager> LoadManagerCreator::createManager()
{
    if (m_manager == nullptr)
        createInstance();

    return m_manager;
}

void LoadManagerCreator::createInstance()
{
    static std::shared_ptr<LoadManager> manager(new LoadManager());

    m_manager = manager;
}
