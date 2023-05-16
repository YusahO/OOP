#pragma once

#include "Errors.hpp"
#include "ReverseTreeIterator.hpp"
#include <utility>

namespace MyBST
{
    template <TreeElement T>
    ReverseTreeIterator<T>::ReverseTreeIterator()
        : m_stack()
    {
    }

    template <TreeElement T>
    ReverseTreeIterator<T>::ReverseTreeIterator(const bst_shared_ptr &root, bool end)
    {
        // if (end)
        // leftmost(root);
        // m_stack.emplace();
        if (!root)
        {
            m_stack.emplace();
        }
        else if (!end)
        {
            root->rightmost_fill_stack(m_stack);
        }
        else
        {
            // leftmost(root);
            root->leftmost_fill_stack(m_stack);
            m_stack.emplace();
        }
        // std::cout << *this << "\n";
    }

    template <TreeElement T>
    ReverseTreeIterator<T>::ReverseTreeIterator(const bst_shared_ptr &node, const bst_shared_ptr &root)
    {
        if (node != nullptr)
        {
            // search(node, root);
            root->search_fill_stack(m_stack, node->get_value());
        }
        else
        {
            // rightmost(root);
            root->rightmost_fill_stack(m_stack);
            // m_stack.emplace(node);
        }
    }

    template <TreeElement T>
    ReverseTreeIterator<T>::ReverseTreeIterator(const ReverseTreeIterator<T> &other)
        : m_stack(other.m_stack)
    {
    }

    template <TreeElement T>
    ReverseTreeIterator<T>::ReverseTreeIterator(ReverseTreeIterator<T> &&other)
        : m_stack(std::move(other.m_stack))
    {
    }

    template <TreeElement T>
    ReverseTreeIterator<T> &ReverseTreeIterator<T>::operator=(const ReverseTreeIterator<T> &other)
    {
        other.check_validity(__LINE__);
        m_stack = other.m_stack;
        return *this;
    }

    template <TreeElement T>
    ReverseTreeIterator<T> &ReverseTreeIterator<T>::operator=(ReverseTreeIterator<T> &&other)
    {
        other.check_validity(__LINE__);
        m_stack = std::move(other.m_stack);
        return *this;
    }

    template <TreeElement T>
    const T &ReverseTreeIterator<T>::operator*() const
    {
        check_validity(__LINE__);
        check_in_bounds(__LINE__);
        return m_stack.top().lock()->get_value();
    }

    template <TreeElement T>
    const T *ReverseTreeIterator<T>::operator->() const
    {
        check_validity(__LINE__);
        check_in_bounds(__LINE__);
        return &(m_stack.top().lock()->m_value);
    }

    template <TreeElement T>
    ReverseTreeIterator<T>::operator bool() const
    {
        return valid() && !m_stack.top().expired();
    }

    template <TreeElement T>
    bool ReverseTreeIterator<T>::valid() const
    {
        return !m_stack.empty();
    }

    template <TreeElement T>
    ReverseTreeIterator<T> &ReverseTreeIterator<T>::operator--() noexcept
    {
        if (!(*this))
            return *this;

        if (m_stack.top().lock()->get_right())
        {
            bst_shared_ptr node = m_stack.top().lock()->get_right();
            node->leftmost_fill_stack(m_stack);
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
    ReverseTreeIterator<T> ReverseTreeIterator<T>::operator++(int) noexcept
    {
        auto saved = *this;
        ++(*this);
        return saved;
    }

    template <TreeElement T>
    ReverseTreeIterator<T> &ReverseTreeIterator<T>::operator++() noexcept
    {
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
            // rightmost(node);
            node->rightmost_fill_stack(m_stack);
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
                    m_stack.emplace();
                    stackNotEmpty = false;
                }
                // stackNotEmpty = !m_stack.empty();
            }
        }

        return *this;
    }

    template <TreeElement T>
    ReverseTreeIterator<T> ReverseTreeIterator<T>::operator--(int) noexcept
    {
        auto saved = *this;
        --(*this);
        return saved;
    }

    template <TreeElement T>
    bool ReverseTreeIterator<T>::operator==(const ReverseTreeIterator<T> &other) const
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
    ptrdiff_t ReverseTreeIterator<T>::operator-(const ReverseTreeIterator<T> &other) const
    {
        return std::distance(other, *this);
    }

    template <TreeElement T>
    void ReverseTreeIterator<T>::reset()
    {
        while (!m_stack.empty())
            m_stack.pop();
    }

    template <TreeElement T>
    void ReverseTreeIterator<T>::check_validity(int line) const
    {
        if (!valid())
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw ExpiredIteratorError(loc.file_name(), loc.function_name(), line, ctime(&timer));
        }
    }

    template <TreeElement T>
    void ReverseTreeIterator<T>::check_in_bounds(int line) const
    {
        if (m_stack.top().expired())
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw IteratorOutOfBoundsError(loc.file_name(), loc.function_name(), line, ctime(&timer));
        }
    }

    // template <TreeElement T>
    // void ReverseTreeIterator<T>::search(const bst_shared_ptr &node, const bst_shared_ptr &root)
    // {
    //     bst_shared_ptr found = root;
    //     while (found && found->m_value != node->m_value)
    //     {
    //         m_stack.emplace(found);
    //         if (found->m_value < node->m_value)
    //             found = found->get_right();
    //         else
    //             found = found->get_left();
    //     }
    //     m_stack.emplace(found);
    // }

}
