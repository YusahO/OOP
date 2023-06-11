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

    virtual bool isVisible() const { return false; };
    virtual bool isComposite() const { return false; };

    virtual Vertex getOrigin() const { return m_origin; };
    virtual std::size_t getId();

    virtual bool add(const std::shared_ptr<BaseObject> &element) { return false; }
    virtual bool remove(const Iterator &iter) { return false; }

    virtual Iterator begin() { return Iterator(); }
    virtual Iterator end() { return Iterator(); }

protected:
    virtual void updateOrigin();

    std::size_t m_id;
    static std::size_t s_next_id;

    Vertex m_origin;
};
