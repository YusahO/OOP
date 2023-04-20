#pragma once

#include "BaseTreeNode.hpp"
#include <memory>

template<typename T>
using BaseTreeRootPtr = std::shared_ptr<BaseTreeNode<T>>;

template<typename T, typename Compare = std::less<T>>
class BaseBinaryTree
{
public:
    friend class Iterator<T>;
    friend class ConstIterator<T>;

    virtual ~BaseBinaryTree() = delete;

    // вставка
    virtual Iterator<T> Insert(Iterator pos, const T &value);
    virtual Iterator<T> Insert(ConstIterator pos, const T &value);

    // поиск
    virtual Iterator<T> Find(const T &value);
    virtual ConstIterator<T> Find(const T &value);

    // удаление
    virtual Iterator<T> Erase(Iterator<T> pos);
    virtual Iterator<T> Erase(ConstIterator<T> pos);
    virtual Iterator<T> Erase(Iterator<T> first, Iterator<T> last);
    virtual Iterator<T> Erase(ConstIterator<T> first, ConstIterator<T> last);
    virtual std::size_t Erase(const T &value);

    BaseTreeRootPtr<T> GetRoot() const noexcept;

protected:
    BaseTreeRootPtr<T> mp_root = nullptr;
    Compare m_comparator;
};
