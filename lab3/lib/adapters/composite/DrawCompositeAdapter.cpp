#include <DrawCompositeAdapter.h>

void DrawCompositeAdapter::setCamera(std::shared_ptr<Camera> camera)
{
    m_camera = camera;
}

void DrawCompositeAdapter::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    m_drawer = drawer;
}

void DrawCompositeAdapter::request()
{
    if (m_adaptee && m_camera && m_drawer)
    {
        for (auto &elem : m_adaptee->m_elements)
        {
            if (elem->isComposite())
            {
                auto adapter = std::make_shared<DrawCompositeAdapter>();
                auto com_sh_ptr = std::dynamic_pointer_cast<Composite>(elem);
                adapter->setAdaptee(com_sh_ptr);
                adapter->setCamera(m_camera);
                adapter->setDrawer(m_drawer);
                adapter->request();
            }
            else
            {
                auto adapter = std::make_shared<DrawCarcassModelAdapter>();
                auto model_sh_ptr = std::dynamic_pointer_cast<CarcassModel>(elem);
                adapter->setAdaptee(model_sh_ptr);
                adapter->setCamera(m_camera);
                adapter->setDrawer(m_drawer);
                adapter->request();
            }
        }
    }
}
