#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "BinarySearchTree.hpp"
#include "BaseTreeIterator.hpp"

namespace MyBST
{

    template <Comparable T>
    class ReverseTreeIterator : public BaseTreeIterator<T>
    {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using difference_type = std::ptrdiff_t;

    private:
        using avl_shared_ptr = typename AVLTree<T>::avl_shared_ptr;
        using avl_weak_ptr = typename AVLTree<T>::avl_weak_ptr;

    public:
        ReverseTreeIterator();
        explicit ReverseTreeIterator(const avl_shared_ptr &root);
        ReverseTreeIterator(const avl_shared_ptr &node, const avl_shared_ptr &root);

        ReverseTreeIterator(const ReverseTreeIterator<T> &other);
        ReverseTreeIterator(ReverseTreeIterator<T> &&other);

        ReverseTreeIterator<T> &operator=(const ReverseTreeIterator<T> &other);
        ReverseTreeIterator<T> &operator=(ReverseTreeIterator<T> &&other);

        const T &operator*();

        operator bool() const;
        bool valid() const;

        ReverseTreeIterator<T> &operator++();
        ReverseTreeIterator<T> operator++(int);

        ReverseTreeIterator<T> &operator--();
        ReverseTreeIterator<T> operator--(int);

        bool operator==(const ReverseTreeIterator<T> &other) const;
        bool operator!=(const ReverseTreeIterator<T> &other) const;

        void recalculate(const avl_shared_ptr &root);

        template <Comparable P>
        friend std::ostream &operator<<(std::ostream &os, const ReverseTreeIterator<P> &iter);

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
std::ostream &operator<<(std::ostream &os, const ReverseTreeIterator<P> &iter)
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

#include "ReverseTreeIterator_impl.hpp"
