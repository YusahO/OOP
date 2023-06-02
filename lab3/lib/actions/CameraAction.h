#pragma once

#include <memory>
#include <cstddef>

#include "BaseAction.h"

using ID = std::shared_ptr<std::size_t>;

class CameraAction : public BaseAction
{
};

class AddCamera: public CameraAction
{
    using Action = size_t(SceneManager::*)(const Vertex &location, const Vertex &direction);
public:
    AddCamera(const ID &id, const Vertex &location, const Vertex &direction);

    virtual void execute() override;

private:
    ID m_id;
    Vertex m_location;
    Vertex m_direction;

    Action m_method;
};


class RemoveCamera: public CameraAction
{
    using Action = void(SceneManager::*)(const size_t id);
public:
    RemoveCamera(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t m_id;
    Action m_method;
};


class TranslateCamera: public CameraAction
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &dx, const double &dy, const double &dz);
public:
    TranslateCamera(const std::shared_ptr<Camera> camera, const double dx, const double dy, const double dz);

    virtual void execute() override;

private:
    std::shared_ptr<Camera> m_camera;
    double m_dx, m_dy, m_dz;
    Action m_method;
};


class RotateCamera: public CameraAction
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &ax, const double &ay, const double &az);
public:
    RotateCamera(const std::shared_ptr<Camera> camera, const double ax, const double ay, const double az);

    virtual void execute() override;

private:
    std::shared_ptr<Camera> m_camera;
    double m_ax, m_ay, m_az;
    Action m_method;
};


class SetCamera: public CameraAction
{
    using Action = void(SceneManager::*)(size_t id);
public:
    explicit SetCamera(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t m_id;
    Action m_method;
};
