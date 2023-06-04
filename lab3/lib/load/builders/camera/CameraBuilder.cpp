#include <CameraBuilder.h>

void CameraBuilder::build()
{
    m_camera = std::make_shared<Camera>();
}

void CameraBuilder::buildLocation(const Vertex &location, const Vertex &direction)
{
    m_camera = std::make_shared<Camera>(location, direction);
}

bool CameraBuilder::isBuild() const
{
    return m_camera != nullptr;
}

std::shared_ptr<Camera> CameraBuilder::get()
{
    return m_camera;
}
