#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "BinarySearchTree.hpp"
#include "BaseTreeIterator.hpp"

namespace MyBST {

template <Comparable T>
class AVLTree;

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
    using avl_shared_ptr = typename AVLTree<T>::avl_shared_ptr;
    using avl_weak_ptr = typename AVLTree<T>::avl_weak_ptr;

public:
    TreeIterator();
    explicit TreeIterator(const avl_shared_ptr &root);
    TreeIterator(const avl_shared_ptr &node, const avl_shared_ptr &root);

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

    void recalculate(const avl_shared_ptr &root);

    template <Comparable P>
    friend std::ostream &operator<<(std::ostream &os, const TreeIterator<P> &iter);

    void leftmost(const avl_shared_ptr &node);
    void rightmost(const avl_shared_ptr &node);

protected:
    void reset();
    void search(const avl_shared_ptr &node, const avl_shared_ptr &root);
    void check_validity(int) const;

private:
    std::stack<avl_weak_ptr> m_stack;
};

template <Comparable P>
std::ostream &operator<<(std::ostream &os, const TreeIterator<P> &iter)
{
    std::stack<std::weak_ptr<typename AVLTree<P>::TreeNode>> st = iter.m_stack;
    os << "[ ";
    while (!st.empty())
    {
        if (st.top().expired())
        {
            os << "null ";
        }
        else
        {
            os << st.top().lock()->m_value << " ";
        }
        st.pop();
    }
    return os << "]";
}

}

#include "TreeIterator_impl.hpp"
