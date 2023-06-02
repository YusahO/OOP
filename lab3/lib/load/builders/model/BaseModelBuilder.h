#pragma once

#include "Mesh.h"
#include "CarcassModel.h"
#include "BaseBuilder.h"

class BaseModelBuilder : public BaseBuilder
{
public:
    BaseModelBuilder() = default;
    ~BaseModelBuilder() = default;

    virtual void build() override = 0;
    virtual void buildVertex(const Vertex &point) = 0;
    virtual void buildEdge(const Edge &edge) = 0;
    virtual bool isBuild() const override = 0;

    virtual std::shared_ptr<CarcassModel> get() = 0;

protected:
    std::shared_ptr<Mesh> m_model;
};
