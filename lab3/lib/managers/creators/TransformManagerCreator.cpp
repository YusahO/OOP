#include "TransformManagerCreator.h"


std::shared_ptr<TransformManager> TransformManagerCreator::createManager()
{
    if (m_manager == nullptr)
        createInstance();

    return m_manager;
}

void TransformManagerCreator::createInstance()
{
    static std::shared_ptr<TransformManager> manager(new TransformManager());
    m_manager = manager;
}
