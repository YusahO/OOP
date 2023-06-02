#include <BaseObject.h>

std::size_t BaseObject::s_next_id = 1;

BaseObject::BaseObject()
{
    m_id = s_next_id++;
}

bool BaseObject::add(const std::shared_ptr<BaseObject> &)
{
    return false;
}

bool BaseObject::remove(const Iterator &)
{
    return false;
}

bool BaseObject::isVisible()
{
    return false;
}

bool BaseObject::isComposite()
{
    return false;
}

void BaseObject::moveElemsToOrigin(const Vertex &)
{
}

void BaseObject::moveElemsToCenter(const Vertex &)
{
}

void BaseObject::transformElems(const Matrix<double> &)
{
}

Iterator BaseObject::begin()
{
    return Iterator();
}

Iterator BaseObject::end()
{
    return Iterator();
}

std::size_t BaseObject::getId()
{
    return m_id;
}
