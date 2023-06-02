#pragma once

#include <Camera.h>
#include <BaseBuilder.h>

class BaseCameraBuilder : public BaseBuilder
{
public:
    BaseCameraBuilder() = default;
    ~BaseCameraBuilder() = default;

    virtual void build() override = 0;
    virtual void buildLocation(const Vertex &location, const Vertex &direction) = 0;
    virtual bool isBuild() const override = 0;

    virtual std::shared_ptr<Camera> get() = 0;

protected:
    std::shared_ptr<Camera> m_camera;
};
