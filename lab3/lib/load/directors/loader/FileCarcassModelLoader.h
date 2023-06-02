#pragma once

#include <fstream>

#include "BaseLoader.h"

class FileCarcassModelLoader : public BaseLoader
{
public:
    FileCarcassModelLoader();
    FileCarcassModelLoader(std::shared_ptr<std::ifstream> &file);

    virtual void open(std::string &fileName) override;
    virtual void close() override;

    virtual std::size_t loadCount() override;
    virtual Vertex loadVertex() override;
    virtual std::vector<Vertex> loadVertices() override;
    virtual std::vector<Edge> loadEdges(int &vertex_amount) override;

private:
    std::shared_ptr<std::ifstream> m_file;
};
