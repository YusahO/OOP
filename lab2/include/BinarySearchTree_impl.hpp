#pragma once

#include "BinarySearchTree.hpp"
#include "Errors.hpp"
#include <utility>
#include <ctime>

namespace MyBST
{
    // template <Comparable T>
    // void print_stack(std::stack<typename AVLTree<T>::avl_shared_ptr> st)
    // {
    //     std::cout << "[ ";
    //     while (!st.empty())
    //     {
    //         if (st.top() == nullptr)
    //         {
    //             std::cout << "null ";
    //         }
    //         else
    //         {
    //             std::cout << st.top()->m_value << " ";
    //         }
    //         st.pop();
    //     }
    //     std::cout << "]\n";
    // }

    template <Comparable T>
    AVLTree<T>::AVLTree()
        : mp_root(nullptr)
    {
    }

    template <Comparable T>
    AVLTree<T>::AVLTree(std::initializer_list<T> lst)
    {
        for (auto val : lst)
        {
            insert(std::move(val));
        }
    }

    template <Comparable T>
    AVLTree<T>::AVLTree(const AVLTree<T> &other)
        : mp_root(other.mp_root)
    {
    }

    template <Comparable T>
    AVLTree<T>::AVLTree(AVLTree<T> &&other)
        : mp_root(std::exchange(other.mp_root, nullptr))
    {
    }

    template <Comparable T>
    AVLTree<T> &AVLTree<T>::operator=(const AVLTree<T> &other)
    {
        mp_root = deep_copy(other.mp_root);
        return *this;
    }

    template <Comparable T>
    AVLTree<T> &AVLTree<T>::operator=(AVLTree<T> &&other)
    {
        mp_root = std::exchange(other.mp_root, nullptr);
        return *this;
    }

    template <Comparable T>
    typename AVLTree<T>::avl_shared_ptr AVLTree<T>::deep_copy(const AVLTree<T>::avl_shared_ptr &other)
    {
        if (!other)
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw TreeCopyError(loc.file_name(), loc.function_name(), __LINE__, ctime(&timer));
        }

        std::stack<AVLTree<T>::avl_shared_ptr> st;
        AVLTree<T>::avl_shared_ptr new_root = try_alloc_node(other->m_value, other->m_height);
        st.push(other);
        st.push(new_root);
        while (!st.empty())
        {
            AVLTree<T>::avl_shared_ptr new_node = st.top();
            st.pop();
            AVLTree<T>::avl_shared_ptr old_node = st.top();
            st.pop();

            if (old_node->mp_left)
            {
                new_node->mp_left = try_alloc_node(old_node->mp_left->m_value, old_node->mp_right->m_height);
                st.push(old_node->mp_left);
                st.push(new_node->mp_left);
            }

            if (old_node->mp_right)
            {
                new_node->mp_right = try_alloc_node(old_node->mp_right->m_value, old_node->mp_right->m_height);
                st.push(old_node->mp_right);
                st.push(new_node->mp_right);
            }
        }
        return new_root;
    }

    template <Comparable T>
    bool AVLTree<T>::insert(const T &value)
    {
        AVLTree<T>::avl_shared_ptr new_node;

        if (!mp_root)
        {
            mp_root = new_node;
            return true;
        }

        AVLTree<T>::avl_shared_ptr curr = mp_root;
        std::stack<AVLTree<T>::avl_shared_ptr> st;

        while (curr)
        {
            st.push(curr);
            if (curr->m_value < value)
                curr = curr->mp_right;
            else if (curr->m_value > value)
                curr = curr->mp_left;
            else
                return false;
        }

        curr = st.top();

        if (curr->m_value < value)
            curr->mp_right = new_node;
        else
            curr->mp_left = new_node;

        st.push(new_node);

        while (st.size() > 1)
        {
            curr = st.top();
            st.pop();

            if (curr == st.top()->mp_left)
                st.top()->mp_left = do_balance(curr);
            else
                st.top()->mp_right = do_balance(curr);
        }
        curr = st.top();
        st.pop();
        mp_root = do_balance(curr);

        return true;
    }

    template <Comparable T>
    bool AVLTree<T>::operator==(const AVLTree &other) const
    {
        for (auto it1 = begin(), it2 = other.begin(); it1 != end() && it2 != other.end(); ++it1, ++it2)
        {
            if (*it1 != *it2)
                return false;
        }
        return true;
    }

    template <Comparable T>
    bool AVLTree<T>::operator!=(const AVLTree &other) const
    {
        return !(*this == other);
    }

    template <Comparable T>
    bool AVLTree<T>::insert(T &&value)
    {
        return insert(value);
    }

    template <Comparable T>
    TreeIterator<T> AVLTree<T>::find(T &&value) const
    {
        AVLTree<T>::avl_shared_ptr found = _find(value);
        return { found, mp_root };
    }

    template <Comparable T>
    TreeIterator<T> AVLTree<T>::find(const T &value) const
    {
        AVLTree<T>::avl_shared_ptr found = _find(value);
        return { found, mp_root };
    }

    template <Comparable T>
    bool AVLTree<T>::contains(const T &value) const
    {
        return _find(value) != nullptr;
    }

    template <Comparable T>
    void AVLTree<T>::clear() noexcept
    {
        mp_root = nullptr;
    }

    template <Comparable T>
    inline bool AVLTree<T>::empty() const noexcept
    {
        return mp_root == nullptr;
    }

    template <Comparable T>
    std::size_t AVLTree<T>::size() const
    {
        std::size_t s = 0;
        for (const auto &p : *this)
            ++s;
        return s;
    }

    template <Comparable T>
    TreeIterator<T> AVLTree<T>::begin() const
    {
        return TreeIterator<T>(mp_root);
    }

    template <Comparable T>
    TreeIterator<T> AVLTree<T>::end() const
    {
        return { mp_root, true };
    }

    template <Comparable T>
    ReverseTreeIterator<T> AVLTree<T>::rbegin() const
    {
        ReverseTreeIterator<T> iter;
        iter.rightmost(mp_root);
        return iter;
    }

    template <Comparable T>
    ReverseTreeIterator<T> AVLTree<T>::rend() const
    {
        return ReverseTreeIterator<T>(mp_root);
    }

    template <Comparable T>
    template <Iterator Iter>
        requires Assignable<typename Iter::value_type, T>
    AVLTree<T>::AVLTree(Iter first, Iter last)
    {
        for (Iter it = first; it != last; ++it)
        {
            insert(*it);
        }
    }

    template <Comparable T>
    template <Container Con>
        requires Convertible<typename Con::value_type, T> &&Assignable<typename Con::value_type, T>
    AVLTree<T>::AVLTree(const Con &container)
    {
        for (const auto &elem : container)
        {
            insert(elem);
        }
    }

    template <Comparable T>
    bool AVLTree<T>::erase(T &&value)
    {
        return erase(value);
    }

    template <Comparable T>
    bool AVLTree<T>::erase(const T &value)
    {
        return _erase(value);
    }

    template <Comparable T>
    template <Iterator Iter>
        requires Assignable<typename Iter::value_type, T>
    bool AVLTree<T>::erase(Iter pos)
    {
        return erase(*pos);
    }

    template <Comparable T>
    bool AVLTree<T>::_erase(const T &value)
    {
        AVLTree<T>::avl_shared_ptr found = mp_root, parent;
        std::stack<avl_shared_ptr> st;

        while (found && found->m_value != value)
        {
            st.push(found);
            parent = found;
            if (found->m_value < value)
                found = found->mp_right;
            else
                found = found->mp_left;
        }

        if (!found)
            return false;

        if (found->mp_left == nullptr || found->mp_right == nullptr)
        {
            AVLTree<T>::avl_shared_ptr new_curr;

            if (found->mp_left == nullptr)
                new_curr = found->mp_right;
            else
                new_curr = found->mp_left;

            if (parent == nullptr)
            {
                mp_root = new_curr;
            }
            else
            {
                if (found == parent->mp_left)
                    parent->mp_left = new_curr;
                else
                    parent->mp_right = new_curr;
            }

            if (new_curr)
            {
                st.push(new_curr);
            }

            while (st.size() > 1)
            {
                found = st.top();
                st.pop();
                if (found == st.top()->mp_left)
                    st.top()->mp_left = do_balance(found);
                else
                    st.top()->mp_right = do_balance(found);
            }
            if (!st.empty())
            {
                found = st.top();
                st.pop();
                mp_root = do_balance(found);
            }
        }
        else
        {
            AVLTree<T>::avl_shared_ptr tmp = found->mp_right;
            parent.reset();
            while (tmp->mp_left)
            {
                parent = tmp;
                tmp = tmp->mp_left;
            }

            if (parent != nullptr)
                parent->mp_left = tmp->mp_right;
            else
                found->mp_right = tmp->mp_right;

            found->m_value = tmp->m_value;
        }

        return true;
    }

    template <Comparable T>
    size_t AVLTree<T>::get_height(const avl_shared_ptr &node) const
    {
        return node ? node->m_height : 0;
    }

    template <Comparable T>
    int AVLTree<T>::get_balance(const avl_shared_ptr &node) const
    {
        return get_height(node->mp_right) - get_height(node->mp_left);
    }

    template <Comparable T>
    void AVLTree<T>::fix_height(avl_shared_ptr &node)
    {
        node->m_height = std::max(get_height(node->mp_left), get_height(node->mp_right)) + 1;
    }

    template <Comparable T>
    typename AVLTree<T>::avl_shared_ptr AVLTree<T>::rotate_right(avl_shared_ptr &node)
    {
        AVLTree<T>::avl_shared_ptr tmp = node->mp_left;
        node->mp_left = tmp->mp_right;
        tmp->mp_right = node;
        fix_height(node);
        fix_height(tmp);
        return tmp;
    }

    template <Comparable T>
    typename AVLTree<T>::avl_shared_ptr AVLTree<T>::rotate_left(avl_shared_ptr &node)
    {
        AVLTree<T>::avl_shared_ptr tmp = node->mp_right;
        node->mp_right = tmp->mp_left;
        tmp->mp_left = node;
        fix_height(node);
        fix_height(tmp);
        return tmp;
    }

    template <Comparable T>
    typename AVLTree<T>::avl_shared_ptr AVLTree<T>::do_balance(avl_shared_ptr &node)
    {
        fix_height(node);
        int balance = get_balance(node);
        if (balance == 2)
        {
            if (get_balance(node->mp_right) < 0)
                node->mp_right = rotate_right(node->mp_right);
            return rotate_left(node);
        }
        else if (balance == -2)
        {
            if (get_balance(node->mp_left) > 0)
                node->mp_left = rotate_left(node->mp_left);
            return rotate_right(node);
        }
        return node;
    }

    template <Comparable T>
    typename AVLTree<T>::avl_shared_ptr AVLTree<T>::_find(const T &value) const
    {
        if (!mp_root)
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw InvalidTreeError(loc.file_name(), loc.function_name(), __LINE__, ctime(&timer));
        }

        AVLTree<T>::avl_shared_ptr node = mp_root;
        while (node && node->m_value != value)
        {
            if (node->m_value < value)
                node = node->mp_right;
            else
                node = node->mp_left;
        }
        return node;
    }

    template <Comparable T>
    std::ostream &AVLTree<T>::_inorder(const AVLTree<T>::avl_shared_ptr &node, std::ostream &os) const
    {
        if (node->mp_left)
        {
            _inorder(node->mp_left, os);
        }

        os << node->m_value << " ";

        if (node->mp_right != nullptr)
        {
            _inorder(node->mp_right, os);
        }
        return os;
    }

    template<Comparable T>
    typename AVLTree<T>::avl_shared_ptr AVLTree<T>::try_alloc_node(const T &value, int height) const
    {
        AVLTree<T>::avl_shared_ptr node;
        try
        {
            node = std::make_shared<TreeNode>(value, height);
        }
        catch (const std::bad_alloc &e)
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw TreeBadAlloc(loc.file_name(), loc.function_name(), __LINE__, ctime(&timer));
        }
        return node;
    }

    template <Comparable T>
    AVLTree<T>::TreeNode::TreeNode()
        : mp_left(nullptr),
        mp_right(nullptr)
    {
    }

    template <Comparable T>
    AVLTree<T>::TreeNode::TreeNode(T &&value, size_t height)
        : m_value(value),
        m_height(height),
        mp_left(nullptr),
        mp_right(nullptr)
    {
    }

    template <Comparable T>
    AVLTree<T>::TreeNode::TreeNode(const T &value, size_t height)
        : m_value(value),
        m_height(height),
        mp_left(nullptr),
        mp_right(nullptr)
    {
    }

    template <Comparable T>
    bool AVLTree<T>::TreeNode::operator!=(const TreeNode &other) const
    {
        return m_value != other.m_value;
    }
}
