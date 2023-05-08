#pragma once

#include "BinarySearchTree.hpp"
#include "Errors.hpp"
#include <utility>

namespace MyBST
{

template <Comparable T>
BST<T>::BST()
    : mp_root(nullptr)
{
}

template <Comparable T>
BST<T>::BST(std::initializer_list<T> lst)
{
    for (auto val : lst)
    {
        insert(std::move(val));
    }
}

template <Comparable T>
BST<T>::BST(const BST<T> &other)
    : mp_root(_deep_copy(other.mp_root))
{
}

template <Comparable T>
BST<T>::BST(BST<T> &&other)
    : mp_root(std::exchange(other.mp_root, nullptr))
{
}

template <Comparable T>
BST<T> &BST<T>::operator=(const BST<T> &other)
{
    mp_root = _deep_copy(other.mp_root);
    return *this;
}

template <Comparable T>
BST<T> &BST<T>::operator=(BST<T> &&other)
{
    mp_root = std::exchange(other.mp_root, nullptr);
    return *this;
}

template <Comparable T>
std::size_t BST<T>::_size(const BST<T>::bst_shared_ptr &node) const
{
    if (!node)
        return 0;
    else
        return (_size(node->mp_left) + 1 + _size(node->mp_right));
}

template <Comparable T>
typename BST<T>::bst_shared_ptr BST<T>::_deep_copy(const BST<T>::bst_shared_ptr &other)
{
    if (!other)
        return nullptr;

    std::stack<BST<T>::bst_shared_ptr> st;
    BST<T>::bst_shared_ptr new_root = std::make_shared<TreeNode>(other->m_value);
    st.push(other);
    st.push(new_root);
    while (!st.empty())
    {
        BST<T>::bst_shared_ptr new_node = st.top();
        st.pop();
        BST<T>::bst_shared_ptr old_node = st.top();
        st.pop();

        if (old_node->mp_left)
        {
            new_node->mp_left = std::make_shared<TreeNode>(old_node->mp_left->m_value);
            st.push(old_node->mp_left);
            st.push(new_node->mp_left);
        }

        if (old_node->mp_right)
        {
            new_node->mp_right = std::make_shared<TreeNode>(old_node->mp_right->m_value);
            st.push(old_node->mp_right);
            st.push(new_node->mp_right);
        }
    }
    return new_root;
}

template <Comparable T>
TreeIterator<T> BST<T>::insert(const T &value)
{
    BST<T>::bst_shared_ptr newNode = std::make_shared<TreeNode>(value);

    if (!mp_root)
    {
        mp_root = newNode;
        return TreeIterator<T>(mp_root);
    }

    BST<T>::bst_shared_ptr curr = mp_root;
    BST<T>::bst_shared_ptr parent = nullptr;

    while (curr)
    {
        parent = curr;
        if (curr->m_value < value)
        {
            curr = curr->mp_right;
        }
        else if (curr->m_value > value)
        {
            curr = curr->mp_left;
        }
        else
        {
            throw TreeValueError(__FILE__, typeid(*this).name(), __LINE__);
        }
    }

    if (parent->m_value < value)
    {
        parent->mp_right = newNode;
    }
    else
    {
        parent->mp_left = newNode;
    }

    return TreeIterator<T>(newNode);
}

template <Comparable T>
TreeIterator<T> BST<T>::insert(T &&value)
{
    return insert(value);
}

template <Comparable T>
TreeIterator<T> BST<T>::find(const T &value)
{
    BST<T>::bst_shared_ptr found = _find(value);
    return {found, mp_root};
}

template <Comparable T>
typename BST<T>::bst_shared_ptr BST<T>::get_root() const
{
    return mp_root;
}

template <Comparable T>
void BST<T>::clean() noexcept
{
    mp_root = nullptr;
}

template <Comparable T>
std::size_t BST<T>::size() const noexcept
{
    return _size(mp_root);
}

template <Comparable T>
TreeIterator<T> BST<T>::begin() const noexcept
{
    return TreeIterator<T>(mp_root);
}

template <Comparable T>
TreeIterator<T> BST<T>::end() const noexcept
{
    TreeIterator<T> iter;
    iter.rightmost(mp_root);
    return ++iter;
}

template <Comparable T>
ReverseTreeIterator<T> BST<T>::rbegin() const noexcept
{
    ReverseTreeIterator<T> iter;
    iter.rightmost(mp_root);
    return iter;
}

template <Comparable T>
ReverseTreeIterator<T> BST<T>::rend() const noexcept
{
    return ReverseTreeIterator<T>(mp_root);
}

template <Comparable T>
BST<T>::bst_shared_ptr BST<T>::find_min(bst_shared_ptr &node) const
{
    while (node->mp_left)
        node = node->mp_left;
    return node;
}

template <Comparable T>
template <Iterator Iter> 
    requires Assignable<typename Iter::value_type, T>
BST<T>::BST(Iter first, Iter last)
{
    for (Iter it = first; it != last; ++it)
    {
        insert(*it);
    }
}

template <Comparable T>
template <Container Con>
    requires Convertible<typename Con::value_type, T> && Assignable<typename Con::value_type, T>
BST<T>::BST(const Con &container)
{
    for (const auto &elem : container)
    {
        insert(elem);
    }
}

template <Comparable T>
template <Iterator Iter>
    requires Assignable<typename Iter::value_type, T>
TreeIterator<T> BST<T>::erase(Iter &pos)
{
    std::pair<BST<T>::bst_shared_ptr, bool> result = _erase(*pos);
    return {result.first, mp_root};
}

template <Comparable T>
template <Iterator Iter>
    requires Assignable<typename Iter::value_type, T>
TreeIterator<T> BST<T>::erase(Iter &first, Iter &last)
{
    Iter it = first;
    while (it != last)
    {
        std::cout << std::endl;
        std::cout << "before erase " << *it << " " << it << " " << last << "\n";
        it = erase(it);
        std::cout << "after erase " << *it << " " << it << " " << last << "\n";
        last.recalculate(mp_root);
    }

    return it;
}

template <Comparable T>
bool BST<T>::erase(const T &value)
{
    std::pair<BST<T>::bst_shared_ptr, bool> result = _erase(value);
    return result.second;
}

template <Comparable T>
std::pair<typename BST<T>::bst_shared_ptr, bool> BST<T>::_erase(const T &value)
{
    BST<T>::bst_shared_ptr found = mp_root, parent;
    while (found && found->m_value != value)
    {
        parent = found;
        if (found->m_value < value)
            found = found->mp_right;
        else
            found = found->mp_left;
    }

    if (!found)
        return {nullptr, false};

    BST<T>::bst_shared_ptr nextAfterDeleted;

    if (found->mp_left == nullptr || found->mp_right == nullptr)
    {
        BST<T>::bst_shared_ptr newCurr;

        if (found->mp_left == nullptr)
            newCurr = found->mp_right;
        else
            newCurr = found->mp_left;

        if (parent == nullptr)
        {
            mp_root = newCurr;
            nextAfterDeleted = nullptr;
        }
        else
        {
            if (found == parent->mp_left)
                parent->mp_left = newCurr;
            else
                parent->mp_right = newCurr;
            nextAfterDeleted = parent;
        }
    }
    else
    {
        BST<T>::bst_shared_ptr tmp = found->mp_right;
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

        nextAfterDeleted = found;
    }

    return {nextAfterDeleted, true};
}

template <Comparable T>
typename BST<T>::bst_shared_ptr BST<T>::_find(const T &value)
{
    BST<T>::bst_shared_ptr node = mp_root;
    while (node && node->m_value != value)
    {
        if (node->m_value < value)
        {
            node = node->mp_right;
        }
        else
        {
            node = node->mp_left;
        }
    }
    return node;
}

template <Comparable T>
std::ostream &BST<T>::_inorder(const BST<T>::bst_shared_ptr &node, std::ostream &os) const
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

template <Comparable T>
BST<T>::TreeNode::TreeNode()
    : mp_left(nullptr),
        mp_right(nullptr)
{
}

template <Comparable T>
BST<T>::TreeNode::TreeNode(T &&value)
    : m_value(value),
      m_height(1),
      mp_left(nullptr),
      mp_right(nullptr)
{
}

template <Comparable T>
BST<T>::TreeNode::TreeNode(const T &value)
    : m_value(value),
      m_height(1),
      mp_left(nullptr),
      mp_right(nullptr)
{
}

template <Comparable T>
BST<T>::TreeNode::TreeNode(T &&value, const bst_shared_ptr &left, const bst_shared_ptr &right)
    : m_value(value),
      m_height(1),
      mp_left(left),
      mp_right(right)
{
}

template <Comparable T>
BST<T>::TreeNode::TreeNode(const T &value, const bst_shared_ptr &left, const bst_shared_ptr &right)
    : m_value(value),
      m_height(1),
      mp_left(left),
      mp_right(right)
{
}

template <Comparable T>
bool BST<T>::TreeNode::operator!=(const TreeNode &other) const
{
    return m_value != other.m_value;
}

}
