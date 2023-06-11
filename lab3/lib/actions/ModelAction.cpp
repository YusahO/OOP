#include <QDebug>

#include "ModelAction.h"


TranslateModel::TranslateModel(const std::shared_ptr<BaseObject> object, const double dx, const double dy, const double dz)
    : m_object(object),
      m_dx(dx),
      m_dy(dy),
      m_dz(dz)
{
    m_method = &TransformManager::translateObject;
}

void TranslateModel::execute()
{
    (*(m_transform_manager).*m_method)(m_object, m_dx, m_dy, m_dz);
}



ScaleModel::ScaleModel(const std::shared_ptr<BaseObject> object, const double kx, const double ky, const double kz)
    : m_object(object),
      m_kx(kx),
      m_ky(ky),
      m_kz(kz)
{
    m_method = &TransformManager::scaleObject;
}

void ScaleModel::execute()
{
    (*(m_transform_manager).*m_method)(m_object, m_kx, m_ky, m_kz);
}



RotateModel::RotateModel(const std::shared_ptr<BaseObject> object, const double ax, const double ay, const double az)
    : m_object(object),
      m_ax(ax),
      m_ay(ay),
      m_az(az)
{
    m_method = &TransformManager::rotateObject;
}

void RotateModel::execute()
{
    (*(m_transform_manager).*m_method)(m_object, m_ax, m_ay, m_az);
}



TransformModel::TransformModel(const std::shared_ptr<BaseObject> object, std::shared_ptr<BaseTransformer> &transformer)
    : m_object(object),
      m_transformer(transformer)
{
    m_method = &TransformManager::transformObject;
}

void TransformModel::execute()
{
    (*(m_transform_manager).*m_method)(m_object, m_transformer);
}



RemoveModel::RemoveModel(const std::size_t id) : m_id(id)
{
    m_method = &SceneManager::retranslateObject;
}

void RemoveModel::execute()
{
    (*(m_scene_manager).*m_method)(m_id);
}



AddModel::AddModel(ID &id, std::shared_ptr<BaseObject> object)
    : m_object(object),
      m_id(id)
{
    m_method = &SceneManager::addObject;
}

void AddModel::execute()
{
    (*m_id) = (*(m_scene_manager).*m_method)(m_object);
}



LoadModel::LoadModel(std::shared_ptr<BaseObject> &object, std::string &filename)
    : m_object(object),
      m_filename(filename)
{
    m_method = &LoadManager::load;
}

void LoadModel::execute()
{
    m_object = (*(m_load_manager).*m_method)(m_filename);
}
