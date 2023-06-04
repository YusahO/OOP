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
    void updateAxes();

    void rotate(double angle) { Y_angle += angle; }
    void rotateCW(double angle) { Z_angle += angle; }

private:
    Vertex m_location;

    double Y_angle;
    double Z_angle;

    Vertex m_direction;
    Vertex m_right;
    Vertex m_up;
};

