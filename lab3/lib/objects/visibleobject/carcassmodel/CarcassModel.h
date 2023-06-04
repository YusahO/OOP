#pragma once 

#include <memory>
#include <utility>

#include "BaseObject.h"
#include "BaseModel.h"
#include "Vertex.h"
#include "Edge.h"
#include "Mesh.h"
#include "DrawCarcassModelAdapter.h"

class CarcassModel : public BaseModel
{
    friend class DrawCarcassModelAdapter;

public:
    CarcassModel();
    explicit CarcassModel(const std::shared_ptr<Mesh> &model_structure);
    CarcassModel(const CarcassModel &model);

    ~CarcassModel() override = default;

    virtual Vertex getCenter() const override;
    virtual void transform(const Matrix<double> &mat, const Vertex &center) override;

protected:
    std::shared_ptr<Mesh> m_mesh;
};

