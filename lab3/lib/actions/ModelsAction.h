#pragma once

#include <cstddef>
#include <memory>

#include "BaseAction.h"


using ID = std::shared_ptr<std::size_t>;

class ModelsAction : public BaseAction
{
};

class TranslateModels : public ModelsAction
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &dx, const double &dy, const double &dz);
public:
    TranslateModels(const std::shared_ptr<BaseObject> objects, const double dx, const double dy, const double dz);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> m_objects;
    double m_dx, m_dy, m_dz;
    Action m_method;
};



class ScaleModels : public ModelsAction
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &kx, const double &ky, const double &kz);
public:
    ScaleModels(const std::shared_ptr<BaseObject> objects, const double kx, const double ky, const double kz);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> m_objects;
    double m_kx, m_ky, m_kz;
    Action m_method;
};



class RotateModels : public ModelsAction
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &ax, const double &ay, const double &az);
public:
    RotateModels(const std::shared_ptr<BaseObject> objects, const double ax, const double ay, const double az);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> m_objects;
    double m_ax, m_ay, m_az;
    Action m_method;
};



class TransformModels : public ModelsAction
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, std::shared_ptr<BaseTransformer> &transformer);
public:
    TransformModels(const std::shared_ptr<BaseObject> objects, std::shared_ptr<BaseTransformer> &transformer);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> m_objects;
    std::shared_ptr<BaseTransformer> m_transformer;
    Action m_method;
};

