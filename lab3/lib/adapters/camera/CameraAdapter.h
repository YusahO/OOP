#pragma once 

#include <BaseAdapter.h>
#include <Camera.h>

class Camera;

class CameraAdapter : public BaseAdapter
{
public:
    virtual ~CameraAdapter() = default;

    void setAdaptee(std::shared_ptr<Camera> adaptee) { m_adaptee = adaptee; };

    virtual void request() = 0;
protected:
    std::shared_ptr<Camera> m_adaptee;
};
