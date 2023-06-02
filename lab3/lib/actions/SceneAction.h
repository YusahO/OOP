#pragma once

#include <memory>
#include <string>

#include "BaseAction.h"

class SceneAction : public BaseAction
{
};

class ClearScene : public SceneAction
{
    using Action = void(DrawManager::*)(std::shared_ptr<BaseDrawer> drawer);
public:
    ClearScene(std::shared_ptr<BaseDrawer> drawer);

    virtual void execute() override;

private:
    std::shared_ptr<BaseDrawer> m_drawer;
    Action m_method;
};

class GetMainCamera : public SceneAction {
    using Action = std::shared_ptr<Camera>(SceneManager::*)() const;
public:
    explicit GetMainCamera(std::shared_ptr<Camera> &camera);

    ~GetMainCamera() override = default;

    void execute() override;

private:
    std::shared_ptr<Camera> &m_camera;
    Action m_method;
};

class GetSceneObjects:public SceneAction
{
    using Action = std::shared_ptr<Composite>(SceneManager::*)();
public:
    GetSceneObjects(std::shared_ptr<Composite> &objects);

    virtual void execute() override;
private:
    std::shared_ptr<Composite> &m_objects;

    Action m_method;
};

class GetSceneObject: public SceneAction
{
    using Action = std::shared_ptr<BaseObject>(SceneManager::*)(const std::size_t id);
public:
    GetSceneObject(std::shared_ptr<BaseObject> &object, const std::size_t id);

    virtual void execute() override;
private:
    std::shared_ptr<BaseObject> &m_object;
    std::size_t m_id;
    Action m_method;
};

class DrawScene : public SceneAction
{
    using Action = void(DrawManager::*)(std::shared_ptr<Scene> scene, std::shared_ptr<BaseDrawer> drawer);
public:
    DrawScene(std::shared_ptr<Scene> scene, std::shared_ptr<BaseDrawer> drawer);

    virtual void execute() override;

private:
    std::shared_ptr<Scene> m_scene;
    std::shared_ptr<BaseDrawer> m_drawer;
    Action m_method;
};

class SetScene: public SceneAction
{
    using Action = void(SceneManager::*)(std::shared_ptr<Scene> &scene);
public:
    SetScene(std::shared_ptr<Scene> scene);

    virtual void execute() override;

private:
    std::shared_ptr<Scene> m_scene;
    Action m_method;
};

class GetScene: public SceneAction
{
    using Action = std::shared_ptr<Scene>(SceneManager::*)() const;
public:
    explicit GetScene(std::shared_ptr<Scene> &scene);

    virtual void execute() override;

private:
    std::shared_ptr<Scene> &m_scene;
    Action m_method;
};

class LoadScene : public SceneAction
{
    using Action = std::shared_ptr<Scene>(LoadManager::*)(std::string &name);
public:
    LoadScene(std::shared_ptr<Scene> &scene, const std::string fileName);

    virtual void execute() override;

private:
    std::shared_ptr<Scene> &m_scene;
    std::string m_fileName;
    Action m_method;
};
