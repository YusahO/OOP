#pragma once

#include <cstddef>

class Edge
{
public:
    Edge() = default;
    Edge(const std::size_t start_point, const std::size_t end_point);
    Edge(const Edge &edge) = default;

    ~Edge() = default;

    std::size_t getStart() const;
    std::size_t getEnd() const;

    void setStart(const std::size_t index);
    void setEnd(const std::size_t index);

private:
    std::size_t m_start;
    std::size_t m_end;
};
