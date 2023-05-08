#pragma once

#include "Errors.hpp"
#include "TreeIterator.hpp"
#include <utility>

namespace MyBST
{

    template <Comparable T>
    TreeIterator<T>::TreeIterator()
        : m_stack()
    {
    }

    template <Comparable T>
    TreeIterator<T>::TreeIterator(const bst_shared_ptr &root)
    {
        leftmost(root);
    }

    template <Comparable T>
    TreeIterator<T>::TreeIterator(const bst_shared_ptr &node, const bst_shared_ptr &root)
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
    const T &TreeIterator<T>::operator*()
    {
        check_validity(__LINE__);
        return m_stack.top().lock()->m_value;
    }

    template <Comparable T>
    TreeIterator<T>::operator bool() const
    {
        return valid();
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

        // if (m_stack.empty() || m_stack.top() == nullptr)
        // {
        //     return *this;
        // }

        if (m_stack.top().lock()->mp_right)
        {
            bst_shared_ptr node = m_stack.top().lock()->mp_right;
            leftmost(node);
        }
        else
        {
            bst_shared_ptr node = m_stack.top().lock();
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
            bst_shared_ptr node = m_stack.top().lock()->mp_left;
            rightmost(node);
        }
        else
        {
            bst_shared_ptr node = m_stack.top().lock();
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
        auto stack1(m_stack);
        auto stack2(other.m_stack);

        while (!stack1.empty() && !stack2.empty())
        {
            std::weak_ptr<int> weakPtr1 = stack1.top();
            std::weak_ptr<int> weakPtr2 = stack2.top();
            if (!weakPtr1.expired() && !weakPtr2.expired())
            {
                std::shared_ptr<int> sptr1 = weakPtr1.lock();
                std::shared_ptr<int> sptr2 = weakPtr2.lock();
                if (*sptr1 != *sptr2)
                {
                    // The two stacks are not equal
                    break;
                }
            }
            stack1.pop();
            stack2.pop();
        }
        if (stack1.empty() && stack2.empty())
        {
        }
    }

    template <Comparable T>
    bool TreeIterator<T>::operator!=(const TreeIterator<T> &other) const
    {
        return !(*this == other);
    }

    template <Comparable T>
    void TreeIterator<T>::recalculate(const bst_shared_ptr &root)
    {
        bst_shared_ptr top = m_stack.top().lock();
        reset();

        if (top != nullptr)
        {
            search(top, root);
        }
        else
        {
            rightmost(root);
            m_stack.emplace(top);
        }
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
            throw TreeOutOfBoundsError(__FILE__, typeid(this).name(), line);
    }

    template <Comparable T>
    void TreeIterator<T>::leftmost(const bst_shared_ptr &node)
    {
        bst_shared_ptr n = node;
        while (n)
        {
            m_stack.emplace(n);
            n = n->mp_left;
        }
    }

    template <Comparable T>
    void TreeIterator<T>::rightmost(const bst_shared_ptr &node)
    {
        bst_shared_ptr n = node;
        while (n)
        {
            m_stack.emplace(n);
            n = n->mp_right;
        }
    }

    template <Comparable T>
    void TreeIterator<T>::search(const bst_shared_ptr &node, const bst_shared_ptr &root)
    {
        bst_shared_ptr found = root;
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
