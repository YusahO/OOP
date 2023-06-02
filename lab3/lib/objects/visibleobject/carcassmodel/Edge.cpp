#include <Edge.h>

Edge::Edge(const std::size_t start_point, const std::size_t end_point)
    : m_start(start_point),
      m_end(end_point)
{
}

std::size_t Edge::getStart() const
{
    return m_start;
}

std::size_t Edge::getEnd() const
{
    return m_end;
}

void Edge::setStart(const std::size_t index)
{
    m_start = index;
}

void Edge::setEnd(const std::size_t index)
{
    m_end = index;
}
