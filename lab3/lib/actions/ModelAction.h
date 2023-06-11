#pragma once

#include <cstddef>
#include <memory>

#include "BaseAction.h"

using ID = std::shared_ptr<std::size_t>;

class ModelAction : public BaseAction { };

class TranslateModel : public ModelAction
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &dx, const double &dy, const double &dz);
public:
    TranslateModel(const std::shared_ptr<BaseObject> object, const double dx, const double dy, const double dz);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> m_object;
    double m_dx, m_dy, m_dz;
    Action m_method;
};


class ScaleModel : public ModelAction
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &kx, const double &ky, const double &kz);
public:
    ScaleModel(const std::shared_ptr<BaseObject> object, const double kx, const double ky, const double kz);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> m_object;
    double m_kx, m_ky, m_kz;
    Action m_method;
};



class RotateModel : public ModelAction
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, const double &ox, const double &oy, const double &oz);
public:
    RotateModel(const std::shared_ptr<BaseObject> object, const double ax, const double ay, const double az);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> m_object;
    double m_ax, m_ay, m_az;
    Action m_method;
};



class TransformModel : public ModelAction
{
    using Action = void(TransformManager::*)(const std::shared_ptr<BaseObject> &object, std::shared_ptr<BaseTransformer> &transformer);
public:
    TransformModel(const std::shared_ptr<BaseObject> object, std::shared_ptr<BaseTransformer> &transformer);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> m_object;
    std::shared_ptr<BaseTransformer> m_transformer;
    Action m_method;
};



class RemoveModel : public ModelAction
{
    using Action = void(SceneManager::*)(const size_t id);
public:
    RemoveModel(const std::size_t id);

    virtual void execute() override;

private:
    std::size_t m_id;
    Action m_method;
};

class AddModel: public ModelAction
{
    using Action = std::size_t(SceneManager::*)(const shared_ptr<BaseObject> &object);
public:
    AddModel(ID &id, shared_ptr<BaseObject> object);

    virtual void execute() override;
private:
    ID &m_id;
    std::shared_ptr<BaseObject> m_object;

    Action m_method;
};

class LoadModel : public ModelAction
{
    using Action = std::shared_ptr<BaseObject>(LoadManager::*)(std::string &name);
public:
    LoadModel(std::shared_ptr<BaseObject> &object, std::string &fileName);

    virtual void execute() override;

private:
    std::shared_ptr<BaseObject> &m_object;
    std::string m_filename;

    Action m_method;
};
