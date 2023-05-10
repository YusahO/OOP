#pragma once

#include "Errors.hpp"
#include "TreeIterator.hpp"
#include <utility>
#include <source_location>

namespace MyBST
{

    template <Comparable T>
    TreeIterator<T>::TreeIterator()
        : m_stack()
    {
    }

    template <Comparable T>
    TreeIterator<T>::TreeIterator(const avl_shared_ptr &root, bool end)
    {
        if (end || !root)
        {
            rightmost(root);
            m_stack.emplace();
        }
        else
        {
            leftmost(root);
        }
    }

    template <Comparable T>
    TreeIterator<T>::TreeIterator(const avl_shared_ptr &node, const avl_shared_ptr &root)
    {
        if (node != nullptr)
        {
            search(node, root);
        }
        else
        {
            rightmost(root);
            m_stack.emplace(node);
        }
    }

    template <Comparable T>
    TreeIterator<T>::TreeIterator(const TreeIterator<T> &other)
        : m_stack(other.m_stack)
    {
    }

    template <Comparable T>
    TreeIterator<T>::TreeIterator(TreeIterator<T> &&other)
        : m_stack(std::move(other.m_stack))
    {
    }

    template <Comparable T>
    TreeIterator<T> &TreeIterator<T>::operator=(const TreeIterator<T> &other)
    {
        other.check_validity(__LINE__);
        m_stack = other.m_stack;
        return *this;
    }

    template <Comparable T>
    TreeIterator<T> &TreeIterator<T>::operator=(TreeIterator<T> &&other)
    {
        other.check_validity(__LINE__);
        m_stack = std::move(other.m_stack);
        return *this;
    }

    template <Comparable T>
    const T &TreeIterator<T>::operator*() const
    {
        check_dereferenceable(__LINE__);
        return m_stack.top().lock()->m_value;
    }

    template <Comparable T>
    const T *TreeIterator<T>::operator->() const
    {
        check_dereferenceable(__LINE__);
        return &(m_stack.top().lock()->m_value);
    }

    template <Comparable T>
    TreeIterator<T>::operator bool() const
    {
        return valid() && !m_stack.top().expired();
    }

    template <Comparable T>
    bool TreeIterator<T>::valid() const
    {
        return !m_stack.empty();
    }

    template <Comparable T>
    TreeIterator<T> &TreeIterator<T>::operator++()
    {
        check_validity(__LINE__);

        if (m_stack.top().lock()->mp_right)
        {
            avl_shared_ptr node = m_stack.top().lock()->mp_right;
            leftmost(node);
        }
        else
        {
            avl_shared_ptr node = m_stack.top().lock();
            m_stack.pop();

            bool stackNotEmpty = !m_stack.empty();
            while (stackNotEmpty && m_stack.top().lock()->mp_right == node)
            {
                node = m_stack.top().lock();
                m_stack.pop();

                if (m_stack.empty())
                    stackNotEmpty = false;
            }

            if (!stackNotEmpty)
            {
                rightmost(node);
                m_stack.emplace();
            }
        }

        return *this;
    }

    template <Comparable T>
    TreeIterator<T> TreeIterator<T>::operator++(int)
    {
        auto saved = *this;
        ++(*this);
        return saved;
    }

    template <Comparable T>
    TreeIterator<T> &TreeIterator<T>::operator--()
    {
        check_validity(__LINE__);

        if (m_stack.top().expired())
        {
            m_stack.pop();
            return *this;
        }

        if (m_stack.top().lock()->mp_left)
        {
            avl_shared_ptr node = m_stack.top().lock()->mp_left;
            rightmost(node);
        }
        else
        {
            avl_shared_ptr node = m_stack.top().lock();
            m_stack.pop();

            bool stackNotEmpty = !m_stack.empty();
            while (stackNotEmpty && m_stack.top().lock()->mp_left == node)
            {
                node = m_stack.top().lock();
                m_stack.pop();
                if (m_stack.empty())
                {
                    leftmost(node);
                }
            }
        }

        return *this;
    }

    template <Comparable T>
    TreeIterator<T> TreeIterator<T>::operator--(int)
    {
        auto saved = *this;
        --(*this);
        return saved;
    }

    template <Comparable T>
    bool TreeIterator<T>::operator==(const TreeIterator<T> &other) const
    {
        if (m_stack.size() != other.m_stack.size())
        {
            return false;
        }

        if (!m_stack.empty() && !other.m_stack.empty())
        {
            avl_shared_ptr f = m_stack.top().lock();
            avl_shared_ptr s = other.m_stack.top().lock();
            return f == s;
        }

        return false;
    }

    template <Comparable T>
    bool TreeIterator<T>::operator!=(const TreeIterator<T> &other) const
    {
        return !(*this == other);
    }

    template <Comparable T>
    void TreeIterator<T>::reset()
    {
        while (!m_stack.empty())
            m_stack.pop();
    }

    template <Comparable T>
    void TreeIterator<T>::check_validity(int line) const
    {
        if (!valid())
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw InvalidIteratorError(loc.file_name(), loc.function_name(), line, ctime(&timer));
        }
    }

    template<Comparable T>
    void TreeIterator<T>::check_dereferenceable(int line) const
    {
        check_validity(line);
        if (m_stack.top().expired())
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw InvalidIteratorError(loc.file_name(), loc.function_name(), line, ctime(&timer));
        }
    }

    template <Comparable T>
    void TreeIterator<T>::leftmost(const avl_shared_ptr &node)
    {
        avl_shared_ptr n = node;
        while (n)
        {
            m_stack.emplace(n);
            n = n->mp_left;
        }
    }

    template <Comparable T>
    void TreeIterator<T>::rightmost(const avl_shared_ptr &node)
    {
        avl_shared_ptr n = node;
        while (n)
        {
            m_stack.emplace(n);
            n = n->mp_right;
        }
    }

    template <Comparable T>
    void TreeIterator<T>::search(const avl_shared_ptr &node, const avl_shared_ptr &root)
    {
        avl_shared_ptr found = root;
        while (found && found->m_value != node->m_value)
        {
            m_stack.emplace(found);
            if (found->m_value < node->m_value)
                found = found->mp_right;
            else
                found = found->mp_left;
        }
        m_stack.emplace(found);
    }

}
