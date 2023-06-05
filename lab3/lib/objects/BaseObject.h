#pragma once

#include <memory>
#include <vector>
#include <QDebug>

#include "Vertex.h"

class BaseObject;

using Iterator = std::vector<std::shared_ptr<BaseObject>>::iterator;

class BaseObject
{
public:
    BaseObject();
    virtual ~BaseObject() = default;
    
    virtual void updateCenter();

    virtual bool isVisible() const = 0;
    virtual bool isComposite() const = 0;

    virtual Vertex getCenter() const = 0;
    virtual void transform(const Matrix<double> &mat, const Vertex &center) = 0;

    virtual std::size_t getId();

protected:
    std::size_t m_id;
    static std::size_t s_next_id;

    Vertex m_center;
};
