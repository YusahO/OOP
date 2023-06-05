#include <BaseObject.h>

std::size_t BaseObject::s_next_id = 1;

BaseObject::BaseObject()
{
    m_id = s_next_id++;
}

void BaseObject::updateOrigin()
{
}

std::size_t BaseObject::getId()
{
    return m_id;
}
