#include <cmath>

#include "TransformManager.h"

static Matrix<double> constructTranslationMatrix(const double &dx, const double &dy, const double &dz)
{
    Matrix<double> mat(4, 4, 0);
    mat[0][0] = 1;
    mat[1][1] = 1;
    mat[2][2] = 1;
    mat[3][3] = 1;
    mat[3][0] = dx;
    mat[3][1] = dy;
    mat[3][2] = dz;
    return mat;
}

static Matrix<double> constructRotationMatrix(const double &ax, const double &ay, const double &az)
{
    Matrix<double> mat(3, 3);

    double cos_ax = cos(ax), sin_ax = sin(ax);
    double cos_ay = cos(ay), sin_ay = sin(ay);
    double cos_az = cos(az), sin_az = sin(az);

    mat[0][0] = cos_ay * cos_az;
    mat[0][1] = sin_ax * sin_ay * cos_az - cos_ax * sin_az;
    mat[0][2] = cos_ax * sin_ay * cos_az + sin_ax * sin_az;

    mat[1][0] = cos_ay * sin_az;
    mat[1][1] = sin_ax * sin_ay * sin_az + cos_ax * cos_az;
    mat[1][2] = cos_ax * sin_ay * sin_az - sin_ax * cos_az;

    mat[2][0] = -sin_ay;
    mat[2][1] = sin_ax * cos_ay;
    mat[2][2] = cos_ax * cos_ay;

    return mat;
}

static Matrix<double> constructScalingMatrix(const double &kx, const double &ky, const double &kz)
{
    Matrix<double> mat(4, 4, 0);

    mat[0][0] = kx;
    mat[1][1] = ky;
    mat[2][2] = kz;
    mat[3][3] = 1;

    return mat;
}

void TransformManager::translateObject(const std::shared_ptr <BaseObject> &object, const double &dx, const double &dy, const double &dz)
{
    Matrix<double> mat = constructTranslationMatrix(dx, dy, dz);
    object->updateCenter();
    object->transform(mat, object->getCenter());
}


void TransformManager::scaleObject(const std::shared_ptr <BaseObject> &object,
    const double &kx,
    const double &ky,
    const double &kz)
{
    Matrix<double> mat = constructScalingMatrix(kx, ky, kz);

    object->updateCenter();
    object->transform(mat, object->getCenter());
}


void TransformManager::rotateObject(const std::shared_ptr <BaseObject> &object,
    const double &ax,
    const double &ay,
    const double &az)
{

    Matrix<double> mat = constructRotationMatrix(ax, ay, az);
    object->updateCenter();
    object->transform(mat, object->getCenter());
}

void TransformManager::transformObject(const std::shared_ptr<BaseObject> &object,
    const Matrix<double> &mat)
{
    object->updateCenter();
    object->transform(mat, object->getCenter());
}
