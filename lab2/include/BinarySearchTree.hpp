#pragma once

#include "common.hpp"
#include "TreeIterator.hpp"
#include "ReverseTreeIterator.hpp"

#include "TreeNode.hpp"

namespace MyBST {

template <Comparable T>
class BinarySearchTree
{
public:
    using iterator = TreeIterator<T>;

public:
    BinarySearchTree() = default;
    explicit BinarySearchTree(std::initializer_list<T> lst);
    template<Container Con>
    explicit BinarySearchTree(const Con& container);

    BinarySearchTree(const BinarySearchTree<T> &other);
    BinarySearchTree(BinarySearchTree<T> &&other) = default;

    BinarySearchTree &operator=(const BinarySearchTree<T> &other) = default;
    BinarySearchTree &operator=(BinarySearchTree<T> &&other) = default;

    virtual ~BinarySearchTree() = default;

    // вставка
    virtual TreeIterator<T> Insert(T &&value);
    virtual TreeIterator<T> Insert(const T &value);

    // поиск
    TreeIterator<T> Find(const T &value);
    // ConstTreeIterator<T> Find(const T &value) const;

    // удаление
    template <class Iter>
    TreeIterator<T> Erase(Iter &pos);
    template <class Iter>
    TreeIterator<T> Erase(Iter &first, Iter &last);
    // template <class Iter>
    // virtual bool Erase(Iter &pos);
    virtual bool Erase(const T &value);

    BSTSharedPtr<T> GetRoot() const;

    virtual void Clean() noexcept;
    // std::size_t GetSize() const noexcept;

    TreeIterator<T> begin() const;
    TreeIterator<T> end() const;
    ReverseTreeIterator<T> rbegin() const;
    ReverseTreeIterator<T> rend() const;

    template <typename P>
    friend std::ostream &operator<<(std::ostream &os, const BinarySearchTree<P> &tree);

protected:
    BSTSharedPtr<T> _DeepCopy(const BSTSharedPtr<T> &other);
    std::pair<BSTSharedPtr<T>, bool> _Erase(const T &value);
    BSTSharedPtr<T> _Find(const T &value);
    std::ostream &_Inorder(const BSTSharedPtr<T> &node, std::ostream &os) const;

private:
    BSTSharedPtr<T> mp_root = nullptr;
};

template <typename P>
std::ostream &operator<<(std::ostream &os, const BinarySearchTree<P> &tree)
{
    os << "{ ";
    tree._Inorder(tree.mp_root, os);
    os << "}";
    return os;
}

}

#include "BinarySearchTree_impl.hpp"
