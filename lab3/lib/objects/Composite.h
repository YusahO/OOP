#pragma once

#include "BaseObject.h"

class Composite : public BaseObject
{
    friend class DrawCompositeAdapter;

public:
    Composite() = default;
    explicit Composite(std::shared_ptr<BaseObject> &element);
    explicit Composite(const std::vector<std::shared_ptr<BaseObject>> &vector);

    virtual bool add(const std::shared_ptr<BaseObject> &element);
    virtual bool remove(const Iterator &iter);
    virtual void updateOrigin() override;

    virtual bool isVisible() const override;
    virtual bool isComposite() const override;

    virtual Vertex getOrigin() const override;
    virtual void moveElemsToOrigin(const Vertex &center);
    virtual void moveElemsToCenter(const Vertex &center);
    virtual void transformElems(const Matrix<double> &mat);
    virtual void transform(const Matrix<double> &mat, const Vertex &center) override;

    virtual Iterator begin();
    virtual Iterator end();

private:
    std::vector<std::shared_ptr<BaseObject>> m_elements;
};

