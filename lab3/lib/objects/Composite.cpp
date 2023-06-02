#include <Composite.h>

Composite::Composite(std::shared_ptr<BaseObject> &element)
{
    m_elements.push_back(element);
    updateCenter();
}


Composite::Composite(const std::vector<std::shared_ptr<BaseObject>> &vector)
{
    m_elements = vector;
    updateCenter();
}


bool Composite::add(const std::shared_ptr<BaseObject> &element)
{
    m_elements.push_back(element);
    updateCenter();

    return true;
}


bool Composite::remove(const Iterator &iter)
{
    m_elements.erase(iter);
    updateCenter();

    return true;
}

void Composite::updateCenter()
{
    m_center = Vertex(0, 0, 0);
    size_t count = 0;

    for (const auto &element : m_elements)
    {
        m_center = m_center + element->getCenter();
        count++;
    }

    m_center = Vertex(m_center.getX() / count,
                     m_center.getY() / count,
                     m_center.getZ() / count);
}

bool Composite::isVisible()
{
    return false;
}

bool Composite::isComposite()
{
    return true;
}

Vertex Composite::getCenter() const
{
    return m_center;
}

void Composite::moveElemsToOrigin(const Vertex &center)
{
    Vertex diff = Vertex(0, 0, 0) - center;

    Matrix<double> mat = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformElems(mat);
    updateCenter();
}

void Composite::moveElemsToCenter(const Vertex &center)
{
    Vertex diff = center - m_center;

    Matrix<double> mat = {{    1,            0,            0,             0      },
                          {    0,            1,            0,             0      },
                          {    0,            0,            1,             0      },
                          {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

    transformElems(mat);
    updateCenter();
}

void Composite::transformElems(const Matrix<double> &mat)
{
    for (const auto &element : m_elements)
    {
        element->updateCenter();
        element->transform(mat, m_center);
    }
}

void Composite::transform(const Matrix<double> &mat, const Vertex &center)
{
    updateCenter();

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
