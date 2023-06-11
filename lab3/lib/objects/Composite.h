#pragma once

#include "BaseObject.h"

class Composite : public BaseObject
{
    friend class DrawCompositeAdapter;
    friend class TransformCompositeAdapter;

public:
    Composite() = default;
    explicit Composite(std::shared_ptr<BaseObject> &element);
    explicit Composite(const std::vector<std::shared_ptr<BaseObject>> &vector);

    virtual bool add(const std::shared_ptr<BaseObject> &element) override;
    virtual bool remove(const Iterator &iter) override;

    virtual bool isVisible() const override;
    virtual bool isComposite() const override;

    virtual Vertex getOrigin() const override;

    virtual Iterator begin() override;
    virtual Iterator end() override;

private:
    virtual void updateOrigin() override;
    std::vector<std::shared_ptr<BaseObject>> m_elements;
};

