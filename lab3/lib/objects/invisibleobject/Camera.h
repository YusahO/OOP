#pragma once

#include "InvisibleObject.h"
#include "DrawCarcassModelAdapter.h"

class Camera : public InvisibleObject
{
    friend class DrawCarcassModelAdapter;

public:
    Camera() = default;
    Camera(const Vertex &location, const Vertex &direction);
    ~Camera() override = default;

    virtual Vertex getCenter() const override;
    void transform(const Matrix<double> &mat, const Vertex &center) override;

private:
    Vertex m_location;
    Vertex m_direction;
};

