#include "ModelsAction.h"

TranslateModels::TranslateModels(const std::shared_ptr<BaseObject> objects, const double dx, const double dy, const double dz)
    : m_objects(objects),
      m_dx(dx),
      m_dy(dy),
      m_dz(dz)
{
    m_method = &TransformManager::translateObject;
}

void TranslateModels::execute()
{
    (*(m_transform_manager).*m_method)(m_objects, m_dx, m_dy, m_dz);
}


ScaleModels::ScaleModels(const std::shared_ptr<BaseObject> objects, const double kx, const double ky, const double kz)
    : m_objects(objects),
      m_kx(kx),
      m_ky(ky),
      m_kz(kz)
{
    m_method = &TransformManager::scaleObject;
}

void ScaleModels::execute()
{
    (*(m_transform_manager).*m_method)(m_objects, m_kx, m_ky, m_kz);
}


RotateModels::RotateModels(const std::shared_ptr<BaseObject> objects, const double ax, const double ay, const double az)
    : m_objects(objects),
      m_ax(ax),
      m_ay(ay),
      m_az(az)
{
    m_method = &TransformManager::rotateObject;
}

void RotateModels::execute()
{
    (*(m_transform_manager).*m_method)(m_objects, m_ax, m_ay, m_az);
}



TransformModels::TransformModels(const std::shared_ptr<BaseObject> objects, std::shared_ptr<BaseTransformer> &transformer)
    : m_objects(objects),
      m_transformer(transformer)
{
    m_method = &TransformManager::transformObject;
}

void TransformModels::execute()
{
    (*(m_transform_manager).*m_method)(m_objects, m_transformer);
}
