#include <QDebug>

#include "CameraAction.h"

AddCamera::AddCamera(const ID &id, const Vertex &location, const Vertex &direction)
    : m_id(id),
      m_location(location),
      m_direction(direction)
{
    m_method = &SceneManager::addCamera;
}

void AddCamera::execute()
{
    (*m_id) = (*(m_scene_manager).*m_method)(m_location, m_direction);
}


RemoveCamera::RemoveCamera(const std::size_t id) : m_id(id)
{
    m_method = &SceneManager::retranslateObject;
}

void RemoveCamera::execute()
{
    (*(m_scene_manager).*m_method)(m_id);
}


TranslateCamera::TranslateCamera(const std::shared_ptr<Camera> camera, const double dx, const double dy, const double dz)
    : m_camera(camera),
      m_dx(dx),
      m_dy(dy),
      m_dz(dz)
{
    m_method = &TransformManager::translateObject;
}

void TranslateCamera::execute()
{
    (*(m_transform_manager).*m_method)(m_camera, m_dx, m_dy, m_dz);
}

RotateCamera::RotateCamera(const std::shared_ptr<Camera> camera, const double ax, const double ay, const double az)
    : m_camera(camera),
      m_ax(ax),
      m_ay(ay),
      m_az(az)
{
    m_method = &TransformManager::rotateObject;
}

void RotateCamera::execute()
{
    m_camera->rotate({m_ax, m_ay, m_az});
    (*(m_transform_manager).*m_method)(m_camera, m_ax, m_ay, m_az);
}


SetCamera::SetCamera(const std::size_t id) : m_id(id)
{
    m_method = &SceneManager::setCamera;
}

void SetCamera::execute()
{
    (*(m_scene_manager).*m_method)(m_id);
}
