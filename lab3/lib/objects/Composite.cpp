#include <Composite.h>
#include "Transformer.h"

Composite::Composite(std::shared_ptr<BaseObject> &element)
{
    m_elements.emplace_back(element);
    updateOrigin();
}


Composite::Composite(const std::vector<std::shared_ptr<BaseObject>> &vector)
{
    m_elements = vector;
    updateOrigin();
}


bool Composite::add(const std::shared_ptr<BaseObject> &element)
{
    m_elements.emplace_back(element);
    updateOrigin();

    return true;
}


bool Composite::remove(const Iterator &iter)
{
    m_elements.erase(iter);
    updateOrigin();

    return true;
}

void Composite::updateOrigin()
{
    m_origin = Vertex(0);

    for (const auto &element : m_elements)
    {
        m_origin = m_origin + element->getOrigin();
    }

    size_t count = m_elements.size();
    m_origin = Vertex(
        m_origin.getX() / count,
        m_origin.getY() / count,
        m_origin.getZ() / count
    );
}

bool Composite::isVisible() const
{
    return false;
}

bool Composite::isComposite() const
{
    return true;
}

Vertex Composite::getOrigin() const
{
    return m_origin;
}

Iterator Composite::begin()
{
    return m_elements.begin();
}


Iterator Composite::end()
{
    return m_elements.end();
}
