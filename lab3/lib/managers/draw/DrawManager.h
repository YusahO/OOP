#pragma once

#include "BaseManager.h"
#include "Vertex.h"
#include "Composite.h"
#include "BaseObject.h"
#include "Scene.h"
#include "BaseDrawer.h"
#include "BaseAdapter.h"
#include "DrawCompositeAdapter.h"

class DrawManager : public BaseManager
{
public:
    DrawManager() = default;
    DrawManager(const DrawManager &manager) = delete;
    DrawManager &operator = (const DrawManager &manager) = delete;

    ~DrawManager() = default;

    void setAdapter(std::shared_ptr<DrawCompositeAdapter> adapter);
    void setCamera(std::shared_ptr<Camera> camera);

    void clearScene(std::shared_ptr<BaseDrawer> drawer);

    void drawScene(std::shared_ptr<Scene> scene, std::shared_ptr<BaseDrawer> drawer);

private:
    std::shared_ptr<DrawCompositeAdapter> m_adapter;
};

