#pragma once

#include "BaseObject.h"

class Composite : public BaseObject
{
    friend class DrawCompositeAdapter;

public:
    Composite() = default;
    explicit Composite(std::shared_ptr<BaseObject> &element);
    explicit Composite(const std::vector<std::shared_ptr<BaseObject>> &vector);

    virtual bool add(const std::shared_ptr<BaseObject> &element) override;
    virtual bool remove(const Iterator &iter) override;
    virtual void updateCenter() override;

    virtual bool isVisible() override;
    virtual bool isComposite() override;

    virtual Vertex getCenter() const override;
    virtual void moveElemsToOrigin(const Vertex &center) override;
    virtual void moveElemsToCenter(const Vertex &center) override;
    virtual void transformElems(const Matrix<double> &mat) override;
    virtual void transform(const Matrix<double> &mat, const Vertex &center) override;

    virtual Iterator begin() override;
    virtual Iterator end() override;

private:
    std::vector<std::shared_ptr<BaseObject>> m_elements;
};

