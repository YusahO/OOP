#pragma once

#include "BaseModelDirector.h"
#include "FileCarcassModelLoader.h"

class FileModelDirector : public BaseModelDirector
{
public:
    FileModelDirector();
    explicit FileModelDirector(std::shared_ptr<FileCarcassModelLoader> &loader);

    ~FileModelDirector() override = default;

    std::shared_ptr<CarcassModel> load(std::shared_ptr<BaseModelBuilder> builder, std::string &filename) override;

protected:
    std::shared_ptr<FileCarcassModelLoader> m_loader;
};
