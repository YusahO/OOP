#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "BSTree.hpp"
#include "BaseTreeIterator.hpp"

namespace MyBST {

template <TreeElement T>
class BSTree;

template <TreeElement T>
class TreeIterator : public BaseTreeIterator
{
public:
    using iterator_category = std::bidirectional_iterator_tag;
    using iterator_concept = std::bidirectional_iterator_tag;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t;

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
    
    explicit operator bool() const;
    bool valid() const;

    TreeIterator<T> &operator++() noexcept;
    TreeIterator<T> operator++(int) noexcept;

    TreeIterator<T> &operator--() noexcept;
    TreeIterator<T> operator--(int) noexcept;

    bool operator==(const TreeIterator &other) const;

    ptrdiff_t operator-(const TreeIterator &other) const;
    
    template <TreeElement P>
    friend std::ostream &operator<<(std::ostream &os, const TreeIterator<P> &iter);

protected:
    void reset();
    void check_validity(int) const;
    void check_in_bounds(int) const;

private:
    std::stack<bst_weak_ptr> m_stack;
};

}

#include "TreeIterator_impl.hpp"
