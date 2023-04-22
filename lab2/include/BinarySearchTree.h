#pragma once

#include <memory>

#include "TreeNode.h"
#include "TreeIterator.h"
#include "ConstTreeIterator.h"

template <typename T>
class TreeNode;


template <typename T>
using BSTWeakPtr = std::weak_ptr<TreeNode<T>>;

template <typename T>
using BSTSharedPtr = std::shared_ptr<TreeNode<T>>;

template <typename T>
class BinarySearchTree
{
public:
    virtual ~BinarySearchTree() = default;

    // вставка
    virtual std::pair<TreeIterator<T>, bool> Insert(T &&value);
    virtual std::pair<TreeIterator<T>, bool> Insert(const T &value);

    // поиск
    // virtual Iterator<T> Find(const T &value) = 0;
    // virtual ConstTreeIterator<T> Find(const T &value) const;

    // удаление
    // template <class Iter>
    // virtual Iterator<T> Erase(Iter<T> pos) = 0;
    // template <class Iter>
    // virtual Iterator<T> Erase(Iter<T> first, Iter<T> last) = 0;
    // virtual std::size_t Erase(const T &value) = 0;

    // virtual void Clean();

protected:
    BSTSharedPtr<T> mp_root = nullptr;
};

#include "BinarySearchTree.hpp"
