#pragma once

#include "BaseModelDirector.h"
#include "FileCarcassModelLoader.h"

class LoadModelDirector : public BaseModelDirector
{
public:
    LoadModelDirector();
    explicit LoadModelDirector(std::shared_ptr<FileCarcassModelLoader> &loader);

    ~LoadModelDirector() override = default;

    std::shared_ptr<CarcassModel> load(std::shared_ptr<BaseModelBuilder> builder, std::string &filename) override;

protected:
    std::shared_ptr<FileCarcassModelLoader> m_loader;
};
