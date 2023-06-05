#pragma once

#include "InvisibleObject.h"
#include "DrawCarcassModelAdapter.h"

class Camera : public InvisibleObject
{
    friend class DrawCarcassModelAdapter;

public:
    Camera() = default;
    Camera(const Vertex &location, const Vertex &angles);
    ~Camera() override = default;

    virtual Vertex getOrigin() const override;
    void transform(const Matrix<double> &mat, const Vertex &center) override;
    // void updateAxes();

    void rotate(const Vertex &angles);

private:
    Vertex m_location;
    Vertex m_angle;
};

