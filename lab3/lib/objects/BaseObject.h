#ifndef BASEOBJECT_H
#define BASEOBJECT_H

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

    virtual bool add(const std::shared_ptr<BaseObject> &);
    virtual bool remove(const Iterator &);
    virtual void updateCenter() {};

    virtual bool isVisible();
    virtual bool isComposite();

    virtual Vertex getCenter() const = 0;
    virtual void moveElemsToOrigin(const Vertex &);
    virtual void moveElemsToCenter(const Vertex &);
    virtual void transformElems(const Matrix<double> &);
    virtual void transform(const Matrix<double> &mat, const Vertex &center) = 0;

    virtual Iterator begin();
    virtual Iterator end();

    virtual std::size_t getId();

protected:
    std::size_t m_id;
    static std::size_t s_next_id;

    Vertex m_center;
};

#endif //BASEOBJECT_H
