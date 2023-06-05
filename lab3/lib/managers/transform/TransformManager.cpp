#include <cmath>

#include "TransformManager.h"
#include "TransformMatrix.h"

void TransformManager::translateObject(const std::shared_ptr <BaseObject> &object,
    const double &dx,
    const double &dy,
    const double &dz)
{
    Matrix<double> mat = TransformMatrix::createTranslationMatrix4(dx, dy, dz);
    object->updateOrigin();
    object->transform(mat, object->getOrigin());
}


void TransformManager::scaleObject(const std::shared_ptr <BaseObject> &object,
    const double &kx,
    const double &ky,
    const double &kz)
{
    Matrix<double> mat = TransformMatrix::createScalingMatrix4(kx, ky, kz);

    object->updateOrigin();
    object->transform(mat, object->getOrigin());
}


void TransformManager::rotateObject(const std::shared_ptr <BaseObject> &object,
    const double &ax,
    const double &ay,
    const double &az)
{

    Matrix<double> mat = TransformMatrix::createRotationMatrix4(ax, ay, az);
    object->updateOrigin();
    object->transform(mat, object->getOrigin());
}

void TransformManager::transformObject(const std::shared_ptr<BaseObject> &object,
    const Matrix<double> &mat)
{
    object->updateOrigin();
    object->transform(mat, object->getOrigin());
}
