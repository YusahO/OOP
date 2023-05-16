#pragma once

#include "Errors.hpp"
#include "TreeIterator.hpp"
#include <utility>
#include <source_location>

namespace MyBST
{

    template <TreeElement T>
    TreeIterator<T>::TreeIterator()
        : m_stack()
    {
    }

    template <TreeElement T>
    TreeIterator<T>::TreeIterator(const bst_shared_ptr &root, bool end)
    {   
        if (!root)
        {
            m_stack.emplace();
        }
        else if (!end)
        {
            // leftmost(root);
            root->leftmost_fill_stack(m_stack);
            // std::cout << *this << "\n";
        }
        else
        {
            // rightmost(root);
            root->rightmost_fill_stack(m_stack);
            m_stack.emplace();
            // m_stack.emplace();
        }
    }

    template <TreeElement T>
    TreeIterator<T>::TreeIterator(const bst_shared_ptr &node, const bst_shared_ptr &root)
    {
        if (node != nullptr)
        {
            root->search_fill_stack(m_stack, node->get_value());
        }
        else
        {
            // rightmost(root);
            root->rightmost_fill_stack(m_stack);
            m_stack.emplace(node);
        }
    }

    template <TreeElement T>
    TreeIterator<T>::TreeIterator(const TreeIterator<T> &other)
        : m_stack(other.m_stack)
    {
    }

    template <TreeElement T>
    TreeIterator<T>::TreeIterator(TreeIterator<T> &&other)
        : m_stack(std::move(other.m_stack))
    {
    }

    template <TreeElement T>
    TreeIterator<T> &TreeIterator<T>::operator=(const TreeIterator<T> &other)
    {
        other.check_validity(__LINE__);
        m_stack = other.m_stack;
        return *this;
    }

    template <TreeElement T>
    TreeIterator<T> &TreeIterator<T>::operator=(TreeIterator<T> &&other)
    {
        other.check_validity(__LINE__);
        m_stack = std::move(other.m_stack);
        return *this;
    }

    template <TreeElement T>
    const T &TreeIterator<T>::operator*() const
    {
        check_validity(__LINE__);
        check_in_bounds(__LINE__);
        return m_stack.top().lock()->get_value();
    }

    template <TreeElement T>
    const T *TreeIterator<T>::operator->() const
    {
        check_validity(__LINE__);
        check_in_bounds(__LINE__);
        return &(m_stack.top().lock()->get_value());
    }

    template <TreeElement T>
    TreeIterator<T>::operator bool() const
    {
        return valid() && !m_stack.top().expired();
    }

    template <TreeElement T>
    bool TreeIterator<T>::valid() const
    {
        return !m_stack.empty();
    }

    template <TreeElement T>
    TreeIterator<T> &TreeIterator<T>::operator++() noexcept
    {
        if (!(*this))
            return *this;

        if (m_stack.top().lock()->get_right())
        {
            bst_shared_ptr node = m_stack.top().lock()->get_right();
            // leftmost(node);
            node->leftmost_fill_stack(m_stack);
            // std::cout << *this << "\n";
        }
        else
        {
            bst_shared_ptr node = m_stack.top().lock();
            m_stack.pop();

            bool stackNotEmpty = !m_stack.empty();
            while (stackNotEmpty && m_stack.top().lock()->get_right() == node)
            {
                node = m_stack.top().lock();
                m_stack.pop();

                if (m_stack.empty())
                    stackNotEmpty = false;
            }

            if (!stackNotEmpty)
            {
                // rightmost(node);
                node->rightmost_fill_stack(m_stack);
                m_stack.emplace();
            }
        }

        return *this;
    }

    template <TreeElement T>
    TreeIterator<T> TreeIterator<T>::operator++(int) noexcept
    {
        auto saved = *this;
        ++(*this);
        return saved;
    }

    template <TreeElement T>
    TreeIterator<T> &TreeIterator<T>::operator--() noexcept
    {
        // check_validity(__LINE__);
        if (m_stack.empty())
            return *this;

        if (m_stack.top().expired())
        {
            m_stack.pop();
            return *this;
        }

        if (m_stack.top().lock()->get_left())
        {
            bst_shared_ptr node = m_stack.top().lock()->get_left();
            rightmost(node);
        }
        else
        {
            bst_shared_ptr node = m_stack.top().lock();
            m_stack.pop();

            bool stackNotEmpty = !m_stack.empty();
            while (stackNotEmpty && m_stack.top().lock()->get_left() == node)
            {
                node = m_stack.top().lock();
                m_stack.pop();
                if (m_stack.empty())
                {
                    // leftmost(node);
                    node->leftmost_fill_stack(m_stack);
                }
            }
        }

        return *this;
    }

    template <TreeElement T>
    TreeIterator<T> TreeIterator<T>::operator--(int) noexcept
    {
        auto saved = *this;
        --(*this);
        return saved;
    }

    template <TreeElement T>
    bool TreeIterator<T>::operator==(const TreeIterator<T> &other) const
    {
        if (m_stack.size() != other.m_stack.size())
        {
            return false;
        }

        if (!m_stack.empty() && !other.m_stack.empty())
        {
            bst_shared_ptr f = m_stack.top().lock();
            bst_shared_ptr s = other.m_stack.top().lock();
            return f == s;
        }

        return false;
    }

    template<TreeElement T>
    ptrdiff_t TreeIterator<T>::operator-(const TreeIterator &other) const
    {
        return std::distance(this, other);
    }

    template <TreeElement T>
    void TreeIterator<T>::reset()
    {
        while (!m_stack.empty())
            m_stack.pop();
    }

    template <TreeElement T>
    void TreeIterator<T>::check_validity(int line) const
    {
        if (!valid())
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw ExpiredIteratorError(loc.file_name(), loc.function_name(), line, ctime(&timer));
        }
    }

    template <TreeElement T>
    void TreeIterator<T>::check_in_bounds(int line) const
    {
        if (m_stack.top().expired())
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw IteratorOutOfBoundsError(loc.file_name(), loc.function_name(), line, ctime(&timer));
        }
    }

    // template <TreeElement T>
    // void TreeIterator<T>::leftmost(const bst_shared_ptr &node)
    // {
    //     bst_shared_ptr n = node;
    //     while (n)
    //     {
    //         m_stack.emplace(n);
    //         n = n->get_left();
    //     }
    // }

    // template <TreeElement T>
    // void TreeIterator<T>::rightmost(const bst_shared_ptr &node)
    // {
    //     bst_shared_ptr n = node;
    //     while (n)
    //     {
    //         m_stack.emplace(n);
    //         n = n->get_right();
    //     }
    // }

    template <TreeElement P>
    std::ostream &operator<<(std::ostream &os, const TreeIterator<P> &iter)
    {
        std::stack<std::weak_ptr<typename BSTree<P>::TreeNode>> st = iter.m_stack;
        os << "[ ";
        while (!st.empty())
        {
            if (st.top().expired())
            {
                os << "null ";
            }
            else
            {
                os << st.top().lock()->get_value() << " ";
            }
            st.pop();
        }
        return os << "]";
    }

}
