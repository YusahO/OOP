#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "BSTree.hpp"
#include "BaseTreeIterator.hpp"

namespace MyBST
{
    template <TreeElement T>
    class ReverseTreeIterator : public BaseTreeIterator
    {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using iterator_concept = std::bidirectional_iterator_tag;
        using value_type = T;
        using pointer = T *;
        using reference = T &;

    private:
        friend BSTree<T>;
        using bst_shared_ptr = typename BSTree<T>::bst_shared_ptr;
        using bst_weak_ptr = typename BSTree<T>::bst_weak_ptr;

    public:
        ReverseTreeIterator();
        ReverseTreeIterator(const bst_shared_ptr &root, bool end = false);
        ReverseTreeIterator(const bst_shared_ptr &node, const bst_shared_ptr &root);

        ReverseTreeIterator(const ReverseTreeIterator<T> &other);
        ReverseTreeIterator(ReverseTreeIterator<T> &&other);

        ReverseTreeIterator<T> &operator=(const ReverseTreeIterator<T> &other);
        ReverseTreeIterator<T> &operator=(ReverseTreeIterator<T> &&other);

        const T &operator*() const;
        const T *operator->() const;

        explicit operator bool() const;
        bool valid() const;

        ReverseTreeIterator<T> &operator++() noexcept;
        ReverseTreeIterator<T> operator++(int) noexcept;

        ReverseTreeIterator<T> &operator--() noexcept;
        ReverseTreeIterator<T> operator--(int) noexcept;

        bool operator==(const ReverseTreeIterator<T> &other) const;

        template <TreeElement P>
        friend std::ostream &operator<<(std::ostream &os, const ReverseTreeIterator<P> &iter);

    protected:
        void reset();
        void check_validity(int) const;
        void check_in_bounds(int) const;

    private:
        std::stack<bst_weak_ptr> m_stack;
    };

    // template <TreeElement P>
    // std::ostream &operator<<(std::ostream &os, const ReverseTreeIterator<P> &iter)
    // {
    //     std::stack<std::weak_ptr<typename BSTree<P>::TreeNode>> st = iter.m_stack;
    //     os << "[ ";
    //     while (!st.empty())
    //     {
    //         if (st.top().expired())
    //         {
    //             os << "null ";
    //         }
    //         else
    //         {
    //             os << st.top().lock()->get_value() << " ";
    //         }
    //         st.pop();
    //     }
    //     return os << "]";
    // }
}

#include "ReverseTreeIterator_impl.hpp"
