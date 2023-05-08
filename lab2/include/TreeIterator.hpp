#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "BinarySearchTree.hpp"
#include "BaseTreeIterator.hpp"

namespace MyBST {

template <Comparable T>
class BST;

template <Comparable T>
class TreeIterator : public BaseTreeIterator<T>
{
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = std::ptrdiff_t;

private:
    using bst_shared_ptr = typename BST<T>::bst_shared_ptr;
    using bst_weak_ptr = typename BST<T>::bst_weak_ptr;

public:
    TreeIterator();
    explicit TreeIterator(const bst_shared_ptr &root);
    TreeIterator(const bst_shared_ptr &node, const bst_shared_ptr &root);

    TreeIterator(const TreeIterator<T> &other);
    TreeIterator(TreeIterator<T> &&other);

    TreeIterator<T> &operator=(const TreeIterator<T> &other);
    TreeIterator<T> &operator=(TreeIterator<T> &&other);

    const T &operator*();

    operator bool() const;
    bool valid() const;

    TreeIterator<T> &operator++();
    TreeIterator<T> operator++(int);

    TreeIterator<T> &operator--();
    TreeIterator<T> operator--(int);

    bool operator==(const TreeIterator<T> &other) const;
    bool operator!=(const TreeIterator<T> &other) const;

    void recalculate(const bst_shared_ptr &root);

    // template <Comparable P>
    // friend std::ostream &operator<<(std::ostream &os, const TreeIterator<P> &iter);

    void leftmost(const bst_shared_ptr &node);
    void rightmost(const bst_shared_ptr &node);

protected:
    void reset();
    void search(const bst_shared_ptr &node, const bst_shared_ptr &root);
    void check_validity(int) const;

private:
    std::stack<bst_weak_ptr> m_stack;
};

// template <Comparable P>
// std::ostream &operator<<(std::ostream &os, const TreeIterator<P> &iter)
// {
//     std::stack<std::weak_ptr<BST<P>::TreeNode>> st = iter.m_stack;
//     os << "[ ";
//     while (!st.empty())
//     {
//         if (st.top().expired())
//         {
//             os << "null ";
//         }
//         else
//         {
//             os << st.top().lock()->m_value << " ";
//         }
//         st.pop();
//     }
//     return os << "]";
// }

}

#include "TreeIterator_impl.hpp"
