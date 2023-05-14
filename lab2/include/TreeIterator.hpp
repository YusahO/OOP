#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "BSTree.hpp"
#include "BaseTreeIterator.hpp"

namespace MyBST {

template <Comparable T>
class BSTree;

template <Comparable T>
class TreeIterator : public BaseTreeIterator
{
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

private:
    friend BSTree<T>;
    using bst_shared_ptr = typename BSTree<T>::bst_shared_ptr;
    using bst_weak_ptr = typename BSTree<T>::bst_weak_ptr;

public:
    TreeIterator();
    TreeIterator(const bst_shared_ptr &root, bool end = false);
    TreeIterator(const bst_shared_ptr &node, const bst_shared_ptr &root);

    TreeIterator(const TreeIterator<T> &other);
    TreeIterator(TreeIterator<T> &&other);

    TreeIterator<T> &operator=(const TreeIterator<T> &other);
    TreeIterator<T> &operator=(TreeIterator<T> &&other);

    const T &operator*() const;
    const T *operator->() const;
    
    operator bool() const;
    bool valid() const;

    TreeIterator<T> &operator++();
    TreeIterator<T> operator++(int);

    TreeIterator<T> &operator--();
    TreeIterator<T> operator--(int);

    bool operator==(const TreeIterator<T> &other) const;
    bool operator!=(const TreeIterator<T> &other) const;
    
    template <Comparable P>
    friend std::ostream &operator<<(std::ostream &os, const TreeIterator<P> &iter);

protected:
    void reset();
    void search(const bst_shared_ptr &node, const bst_shared_ptr &root);
    void check_validity(int) const;
    void check_in_bounds(int) const;

private:
    std::stack<bst_weak_ptr> m_stack;
};

}

#include "TreeIterator_impl.hpp"
