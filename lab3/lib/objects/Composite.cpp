#include <Composite.h>
#include "TransformMatrix.h"

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

void Composite::moveElemsToOrigin(const Vertex &center)
{
    Vertex diff = Vertex(0) - center;

    Matrix<double> mat = TransformMatrix::createTranslationMatrix4(diff.getX(),  diff.getY(),  diff.getZ());
    transformElems(mat);
    updateOrigin();
}

void Composite::moveElemsToCenter(const Vertex &center)
{
    Vertex diff = center - m_origin;

    Matrix<double> mat = TransformMatrix::createTranslationMatrix4(diff.getX(),  diff.getY(),  diff.getZ());

    transformElems(mat);
    updateOrigin();
}

void Composite::transformElems(const Matrix<double> &mat)
{
    for (const auto &element : m_elements)
    {
        element->updateOrigin();
        element->transform(mat, m_origin);
    }
}

void Composite::transform(const Matrix<double> &mat, const Vertex &center)
{
    updateOrigin();

    moveElemsToOrigin(center);
    transformElems(mat);
    moveElemsToCenter(center);
}

Iterator Composite::begin()
{
    return m_elements.begin();
}


Iterator Composite::end()
{
    return m_elements.end();
}
