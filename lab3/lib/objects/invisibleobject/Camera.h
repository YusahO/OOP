#pragma once

#include "InvisibleObject.h"
#include "DrawCarcassModelAdapter.h"
#include "TransformCarcassModelAdapter.h"
#include "TransformCameraAdapter.h"

class Camera : public InvisibleObject
{
    friend class DrawCarcassModelAdapter;
    friend class TransformCarcassModelAdapter;
    friend class TransformCameraAdapter;

public:
    Camera() = default;
    Camera(const Vertex &location, const Vertex &angles);
    ~Camera() override = default;

    virtual Vertex getOrigin() const override;
    // void updateAxes();

    void rotate(const Vertex &angles);

private:
    Vertex m_location;
    Vertex m_angle;
};

