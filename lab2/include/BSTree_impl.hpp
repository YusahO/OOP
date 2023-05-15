#pragma once

#include "BSTree.hpp"
#include "Errors.hpp"
#include <utility>
#include <ctime>
#include <vector>

namespace MyBST
{

    template <TreeElement T>
    BSTree<T>::BSTree()
        : mp_root(nullptr)
    {
    }

    template <TreeElement T>
    BSTree<T>::BSTree(std::initializer_list<T> lst)
    {
        for (auto val : lst)
        {
            insert(std::move(val));
        }
    }

    template <TreeElement T>
    BSTree<T>::BSTree(const BSTree<T> &other)
        : mp_root(deep_copy(other.mp_root))
    {
    }

    template <TreeElement T>
    BSTree<T>::BSTree(BSTree<T> &&other)
        : mp_root(std::exchange(other.mp_root, nullptr))
    {
    }

    template <TreeElement T>
    BSTree<T> &BSTree<T>::operator=(const BSTree<T> &other)
    {
        mp_root = deep_copy(other.mp_root);
        return *this;
    }

    template <TreeElement T>
    BSTree<T> &BSTree<T>::operator=(BSTree<T> &&other)
    {
        mp_root = std::exchange(other.mp_root, nullptr);
        return *this;
    }

    template <TreeElement T>
    typename BSTree<T>::bst_shared_ptr BSTree<T>::deep_copy(const BSTree<T>::bst_shared_ptr &other)
    {
        if (!other)
            return nullptr;

        std::stack<BSTree<T>::bst_shared_ptr> st;
        BSTree<T>::bst_shared_ptr new_root = try_alloc_node(T{other->get_value()});
        st.push(other);
        st.push(new_root);
        while (!st.empty())
        {
            BSTree<T>::bst_shared_ptr new_node = st.top();
            st.pop();
            BSTree<T>::bst_shared_ptr old_node = st.top();
            st.pop();

            if (old_node->get_left())
            {
                const T &value = old_node->get_left()->get_value();
                new_node->set_left(try_alloc_node(T{value}));
                st.push(old_node->get_left());
                st.push(new_node->get_left());
            }

            if (old_node->get_right())
            {
                new_node->set_right(
                    try_alloc_node(T{old_node->get_right()->get_value()}));
                st.push(old_node->get_right());
                st.push(new_node->get_right());
            }
        }
        return new_root;
    }

    template <TreeElement T>
    bool BSTree<T>::operator==(const BSTree &other) const
    {
        for (auto it1 = begin(), it2 = other.begin(); it1 != end() && it2 != other.end(); ++it1, ++it2)
        {
            if (*it1 != *it2)
                return false;
        }
        return true;
    }

    template<TreeElement T>
    template<typename...Args>
    bool BSTree<T>::insert(Args&&... args)
    {
        BSTree<T>::bst_shared_ptr new_node = try_alloc_node(T(std::forward<Args>(args)...));

        if (!mp_root)
        {
            mp_root = new_node;
            return true;
        }
        return mp_root->insert(new_node);
    }

    template <TreeElement T>
    bool BSTree<T>::insert(const T &value)
    {
        BSTree<T>::bst_shared_ptr new_node = try_alloc_node(T(value));

        if (!mp_root)
        {
            mp_root = new_node;
            return true;
        }
        return mp_root->insert(new_node);
    }

    template<TreeElement T>
    bool BSTree<T>::TreeNode::insert(bst_shared_ptr node)
    {
        BSTree<T>::bst_shared_ptr curr = std::const_pointer_cast<BSTree<T>::TreeNode>(this->shared_from_this());
        BSTree<T>::bst_shared_ptr parent = curr;

        while (curr)
        {
            parent = curr;
            if (curr->get_value() < node->get_value())
                curr = curr->get_right();
            else if (curr->get_value() > node->get_value())
                curr = curr->get_left();
            else
                return false;
        }

        if (parent->get_value() < node->get_value())
            parent->set_right(node);
        else
            parent->set_left(node);

        return true;
    }

    template <TreeElement T>
    TreeIterator<T> BSTree<T>::find(const T &value) const
    {
        BSTree<T>::bst_shared_ptr found = _find(value);
        return { found, mp_root };
    }

    template <TreeElement T>
    bool BSTree<T>::contains(const T &value) const
    {
        return _find(value) != nullptr;
    }

    template <TreeElement T>
    void BSTree<T>::clear() noexcept
    {
        mp_root = nullptr;
    }

    template <TreeElement T>
    inline bool BSTree<T>::empty() const noexcept
    {
        return mp_root == nullptr;
    }

    template <TreeElement T>
    std::size_t BSTree<T>::size() const noexcept
    {
        std::size_t s = 0;
        for (const auto &p : *this)
            ++s;
        return s;
    }

    template <TreeElement T>
    BSTree<T> BSTree<T>::get_union(const BSTree &other) const
    {
        BSTree result;

        for (const auto &elem : *this)
            result.insert(elem);

        for (const auto &elem : other)
            result.insert(elem);

        return result;
    }

    template <TreeElement T>
    BSTree<T> BSTree<T>::get_intersection(const BSTree &other) const
    {
        BSTree result;

        for (const auto &elem : *this)
        {
            if (other.contains(elem))
                result.insert(elem);
        }

        return result;
    }

    template <TreeElement T>
    BSTree<T> BSTree<T>::get_difference(const BSTree &other) const
    {
        BSTree result;

        for (const auto &elem : *this)
        {
            if (!other.contains(elem))
                result.insert(elem);
        }

        return result;
    }

    template <TreeElement T>
    BSTree<T> BSTree<T>::get_sym_difference(const BSTree &other) const
    {
        BSTree result;

        for (const auto &elem : *this)
        {
            if (!other.contains(elem))
                result.insert(elem);
        }

        for (const auto &elem : other)
        {
            if (!contains(elem))
                result.insert(elem);
        }

        return result;
    }

    template <TreeElement T>
    TreeIterator<T> BSTree<T>::begin() const
    {
        return { mp_root };
    }

    template <TreeElement T>
    TreeIterator<T> BSTree<T>::end() const
    {
        return { mp_root, true };
    }

    template <TreeElement T>
    ReverseTreeIterator<T> BSTree<T>::rbegin() const
    {
        return { mp_root };
    }

    template <TreeElement T>
    ReverseTreeIterator<T> BSTree<T>::rend() const
    {
        return { mp_root, true };
    }

    template <TreeElement T>
    template <Iterator Iter>
        requires Assignable<typename Iter::value_type, T>
    BSTree<T>::BSTree(Iter first, Iter last)
    {
        for (Iter it = first; it != last; ++it)
        {
            insert(*it);
        }
    }

    template <TreeElement T>
    template <Container Con>
        requires Convertible<typename Con::value_type, T> &&Assignable<typename Con::value_type, T>
    BSTree<T>::BSTree(const Con &container)
    {
        for (const auto &elem : container)
        {
            insert(elem);
        }
    }

    template <TreeElement T>
    template <Iterator Iter>
        requires Assignable<typename Iter::value_type, T>
    bool BSTree<T>::erase(Iter pos)
    {
        return erase(*pos);
    }

    template <TreeElement T>
    bool BSTree<T>::erase(const T &value)
    {
        BSTree<T>::bst_shared_ptr found = mp_root, parent;

        while (found && found->get_value() != value)
        {
            parent = found;
            if (found->get_value() < value)
                found = found->get_right();
            else
                found = found->get_left();
        }

        if (!found)
            return false;

        if (found->get_left() == nullptr || found->get_right() == nullptr)
        {
            BSTree<T>::bst_shared_ptr new_curr;

            if (found->get_left() == nullptr)
                new_curr = found->get_right();
            else
                new_curr = found->get_left();

            if (parent == nullptr)
            {
                mp_root = new_curr;
            }
            else
            {
                if (found == parent->get_left())
                    parent->set_left(new_curr);
                else
                    parent->set_right(new_curr);
            }
        }
        else
        {
            BSTree<T>::bst_shared_ptr tmp = found->get_right();
            parent.reset();
            while (tmp->get_left())
            {
                parent = tmp;
                tmp = tmp->get_left();
            }

            if (parent != nullptr)
                parent->set_left(tmp->get_right());
            else
                found->set_right(tmp->get_right());

            found->set_value(tmp->get_value());
        }

        return true;
    }

    template <TreeElement T>
    std::vector<typename BSTree<T>::bst_shared_ptr> BSTree<T>::ravel() const
    {
        std::vector<typename BSTree<T>::bst_shared_ptr> nodes;
        nodes.reserve(size());
        std::stack<typename BSTree<T>::bst_shared_ptr> st;

        BSTree<T>::bst_shared_ptr curr = mp_root;

        while (curr != nullptr || !st.empty())
        {
            if (curr != nullptr)
            {
                st.emplace(curr);
                curr = curr->get_left();
            }
            else
            {
                curr = st.top();
                st.pop();

                nodes.emplace_back(curr);

                curr = curr->get_right();
            }
        }

        return nodes;
    }

    template <TreeElement T>
    void BSTree<T>::balance()
    {
        std::vector<typename BSTree<T>::bst_shared_ptr> nodes{ravel()};

        size_t len = nodes.size();
        size_t mid = len / 2;

        BSTree<T>::bst_shared_ptr node = nodes[mid];
        mp_root = node;

        std::stack<std::pair<typename BSTree<T>::bst_shared_ptr, std::pair<size_t, size_t>>> st;
        // st.emplace(node, std::make_pair<size_t, size_t>(0, std::move(len)));
        st.emplace(node, std::pair<size_t, size_t>{0, len});
        while (!st.empty())
        {
            auto node_and_bounds = st.top();
            st.pop();

            node = node_and_bounds.first;
            size_t left = node_and_bounds.second.first;
            size_t right = node_and_bounds.second.second;

            mid = (right + left) / 2;

            if (mid < right - 1)
            {
                auto child = nodes[(mid + 1 + right) / 2];
                child->set_left(nullptr), child->set_right(nullptr);
                node->set_right(child);
                // st.emplace(child, std::make_pair<size_t, size_t>(mid + 1, std::move(right)));
                st.emplace(child, std::pair<size_t, size_t>{mid + 1, right});
            }
            if (left < mid)
            {
                auto child = nodes[(left + mid) / 2];
                child->set_left(nullptr), child->set_right(nullptr);
                node->set_left(child);
                // st.emplace(child, std::make_pair<size_t, size_t>(std::move(left), std::move(mid)));
                st.emplace(child, std::pair<size_t, size_t>{left, mid});
            }
        }
    }

    template <TreeElement T>
    typename BSTree<T>::bst_shared_ptr BSTree<T>::_find(const T &value) const
    {
        if (!mp_root)
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw EmptyTreeError(loc.file_name(), loc.function_name(), __LINE__, ctime(&timer));
        }

        BSTree<T>::bst_shared_ptr node = mp_root;
        return node->search(value);
    }

    template <TreeElement T>
    typename BSTree<T>::bst_shared_ptr BSTree<T>::try_alloc_node(T &&value) const
    {
        BSTree<T>::bst_shared_ptr node;
        try
        {
            node = std::make_shared<TreeNode>(value);
        }
        catch (const std::bad_alloc &e)
        {
            time_t timer = time(nullptr);
            auto loc = std::source_location::current();
            throw TreeNodeBadAlloc(loc.file_name(), loc.function_name(), __LINE__, ctime(&timer));
        }
        return node;
    }

    template <TreeElement T>
    BSTree<T>::TreeNode::TreeNode()
        : m_value{},
        mp_left(nullptr),
        mp_right(nullptr)
    {
    }

    template <TreeElement T>
    BSTree<T>::TreeNode::TreeNode(T &&value)
        : m_value(value),
        mp_left(nullptr),
        mp_right(nullptr)
    {
    }

    template <TreeElement T>
    BSTree<T>::TreeNode::TreeNode(const T &value)
        : m_value(value),
        mp_left(nullptr),
        mp_right(nullptr)
    {
    }

    template <TreeElement T>
    inline const T &BSTree<T>::TreeNode::get_value() const noexcept
    {
        return m_value;
    }

    template <TreeElement T>
    inline void BSTree<T>::TreeNode::set_value(const T &value) noexcept
    {
        m_value = value;
    }

    template <TreeElement T>
    bool BSTree<T>::TreeNode::operator!=(const TreeNode &other) const
    {
        return m_value != other.m_value;
    }

    template <TreeElement T>
    const typename BSTree<T>::bst_shared_ptr &BSTree<T>::TreeNode::get_left() const noexcept
    {
        return mp_left;
    }

    template <TreeElement T>
    inline void BSTree<T>::TreeNode::set_left(const bst_shared_ptr &node) noexcept
    {
        mp_left = node;
    }

    template <TreeElement T>
    const typename BSTree<T>::bst_shared_ptr &BSTree<T>::TreeNode::get_right() const noexcept
    {
        return mp_right;
    }

    template <TreeElement T>
    inline void BSTree<T>::TreeNode::set_right(const bst_shared_ptr &node) noexcept
    {
        mp_right = node;
    }

    template <TreeElement T>
    typename BSTree<T>::bst_shared_ptr BSTree<T>::TreeNode::get_leftmost() noexcept
    {
        BSTree<T>::bst_shared_ptr tmp = mp_left;

        if (!tmp)
            return get_this();

        while (tmp)
            tmp = tmp->mp_left;

        return tmp;
    }

    template <TreeElement T>
    typename BSTree<T>::bst_shared_ptr BSTree<T>::TreeNode::get_rightmost() noexcept
    {
        BSTree<T>::bst_shared_ptr tmp = mp_right;

        if (!tmp)
            return get_this();

        while (tmp)
            tmp = tmp->mp_right;

        return tmp;
    }

    template <TreeElement T>
    typename BSTree<T>::bst_shared_ptr BSTree<T>::TreeNode::search(const T &value) const
    {
        auto found = this->shared_from_this();
        while (found && found->m_value != value)
        {
            if (found->m_value < value)
                found = found->mp_right;
            else
                found = found->mp_left;
        }

        return std::const_pointer_cast<BSTree<T>::TreeNode>(found);
    }

    template <TreeElement T>
    void BSTree<T>::TreeNode::search_fill_stack(std::stack<bst_weak_ptr> &stack, const T &value) const
    {
        BSTree<T>::bst_shared_ptr found = std::const_pointer_cast<BSTree<T>::TreeNode>(this->shared_from_this());
        while (found && found->m_value != value)
        {
            stack.emplace(found);
            if (found->m_value < value)
                found = found->mp_right;
            else
                found = found->mp_left;
        }
        if (!found)
            stack.emplace();
        else
            stack.emplace(found);
    }

    template <TreeElement T>
    void BSTree<T>::TreeNode::leftmost_fill_stack(std::stack<bst_weak_ptr> &stack) noexcept
    {
        BSTree<T>::bst_shared_ptr tmp = mp_left;
        stack.emplace(get_this());

        while (tmp)
        {
            stack.emplace(tmp);
            tmp = tmp->mp_left;
        }
    }

    template <TreeElement T>
    void BSTree<T>::TreeNode::rightmost_fill_stack(std::stack<bst_weak_ptr> &stack) noexcept
    {
        BSTree<T>::bst_shared_ptr tmp = mp_right;
        stack.emplace(get_this());

        while (tmp)
        {
            stack.emplace(tmp);
            tmp = tmp->mp_right;
        }
    }

    template <TreeElement T>
    inline typename BSTree<T>::bst_shared_ptr BSTree<T>::TreeNode::get_this()
    {
        return this->shared_from_this();
    }

    template <typename P>
    std::ostream &operator<<(std::ostream &os, const BSTree<P> &tree)
    {
        // os << "{ ";
        // tree._print(tree.mp_root, os);
        // os << "}";
        if (tree.empty())
        {
            os << "{ empty }";
        }
        else
        {
            os << "{ ";
            for (const auto &elem : tree)
                os << elem << " ";
            os << "}";
        }
        return os;
    }
}
