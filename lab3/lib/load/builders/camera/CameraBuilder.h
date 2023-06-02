#pragma once

#include "BaseCameraBuilder.h"

class CameraBuilder : public BaseCameraBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() = default;

    void build() override;
    void buildLocation(const Vertex &location, const Vertex &direction) override;
    bool isBuild() const override;

    std::shared_ptr<Camera> get() override;
};

