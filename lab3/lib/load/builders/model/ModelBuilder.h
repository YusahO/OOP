#pragma once 

#include <BaseModelBuilder.h>

class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder() = default;
    ~ModelBuilder() = default;

    void build() override;
    void buildVertex(const Vertex &point) override;
    void buildEdge(const Edge &edge) override;
    bool isBuild() const override;

    std::shared_ptr<CarcassModel> get() override;
};

