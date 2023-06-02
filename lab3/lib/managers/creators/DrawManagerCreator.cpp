#include <DrawManagerCreator.h>


std::shared_ptr<DrawManager> DrawManagerCreator::createManager()
{
    if (m_manager == nullptr)
        createInstance();

    return m_manager;
}


void DrawManagerCreator::createInstance()
{
    static std::shared_ptr<DrawManager> manager(new DrawManager());
    m_manager = manager;
}
