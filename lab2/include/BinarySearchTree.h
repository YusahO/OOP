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
    BinarySearchTree() = default;
    BinarySearchTree(std::initializer_list<T> lst);
    virtual ~BinarySearchTree() = default;

    // вставка
    virtual TreeIterator<T> Insert(T &&value);
    virtual TreeIterator<T> Insert(const T &value);

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

    template<typename P>
    friend std::ostream &operator<<(std::ostream &os, const BinarySearchTree<P> &tree);

protected:
    std::ostream &Inorder(const BSTNodeSharedPtr<T> &node, std::ostream &os) const;

private:
    BSTSharedPtr<T> mp_root = nullptr;
};

template<typename P>
std::ostream &operator<<(std::ostream &os, const BinarySearchTree<P> &tree)
{
    return tree->Inorder(tree->mp_root, os);
}

#include "BinarySearchTree.hpp"
