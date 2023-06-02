#pragma once

#include "BaseManager.h"
#include "Scene.h"
#include "Camera.h"

class SceneManager : public BaseManager
{
public:
    SceneManager();
    SceneManager(const SceneManager &scene) = delete;
    SceneManager &operator = (const SceneManager &scene) = delete;

    ~SceneManager() = default;

    std::shared_ptr<Scene> getScene() const;
    std::shared_ptr<Camera> getCamera() const;
    std::shared_ptr<BaseObject> getObject(const size_t id);
    std::shared_ptr<Composite> getVisibleObjects();

    size_t addCamera(const Vertex &location, const Vertex &direction);
    size_t addObject(const shared_ptr<BaseObject> &object);

    void retranslateObject(const size_t id);

    void setScene(std::shared_ptr<Scene> &scene);
    void setCamera(const std::size_t id);

private:
    std::shared_ptr<Camera> m_camera;
    std::shared_ptr<Scene> m_scene;
};
