#pragma once

#include "common.hpp"
#include "BaseTree.hpp"
#include "TreeIterator.hpp"
#include "ReverseTreeIterator.hpp"

#include <fstream>

namespace MyBST
{

    template <Comparable T>
    class AVLTree : BaseTree
    {
    public:
        friend class TreeIterator<T>;
        friend class ReverseTreeIterator<T>;

        using iterator = TreeIterator<T>;
        using reverse_iterator = ReverseTreeIterator<T>;
        using const_iterator = const TreeIterator<T>;
        using const_reverse_iterator = const ReverseTreeIterator<T>;
        using value_type = T;
        using size_type = size_t;

    private:
        class TreeNode;
        using avl_shared_ptr = typename std::shared_ptr<TreeNode>;
        using avl_weak_ptr = typename std::weak_ptr<TreeNode>;

    private:
        struct TreeNode
        {
            TreeNode();
            explicit TreeNode(T &&value, size_t height = 1);
            explicit TreeNode(const T &value, size_t height = 1);

            bool operator!=(const TreeNode &other) const;

            T m_value;
            size_t m_height;
            avl_shared_ptr mp_left;
            avl_shared_ptr mp_right;
        };

    public:
        AVLTree();
        explicit AVLTree(std::initializer_list<T> lst);

        template <Iterator Iter>
            requires Assignable<typename Iter::value_type, T>
        explicit AVLTree(Iter first, Iter last);

        template <Container Con>
            requires Convertible<typename Con::value_type, T> &&Assignable<typename Con::value_type, T>
        explicit AVLTree(const Con &container);

        AVLTree(const AVLTree<T> &other);
        AVLTree(AVLTree<T> &&other);
        AVLTree &operator=(const AVLTree<T> &other);
        AVLTree &operator=(AVLTree<T> &&other);

        ~AVLTree() = default;

        bool operator==(const AVLTree &other) const;
        bool operator!=(const AVLTree &other) const;

        // вставка
        bool insert(T &&value);
        bool insert(const T &value);

        // поиск
        TreeIterator<T> find(T &&value) const;
        TreeIterator<T> find(const T &value) const;
        bool contains(const T &value) const;

        // удаление
        template <Iterator Iter>
            requires Assignable<typename Iter::value_type, T>
        bool erase(Iter pos);
        bool erase(T &&value);
        bool erase(const T &value);

        void clear() noexcept;
        bool empty() const noexcept;
        std::size_t size() const override;

        TreeIterator<T> begin() const;
        TreeIterator<T> end() const;
        ReverseTreeIterator<T> rbegin() const;
        ReverseTreeIterator<T> rend() const;

        template <typename P>
        friend std::ostream &operator<<(std::ostream &os, const AVLTree<P> &tree);

    protected:
        // методы АВЛ-дерева
        size_t get_height(const avl_shared_ptr &node) const;
        int get_balance(const avl_shared_ptr &node) const;
        void fix_height(avl_shared_ptr &node);
        avl_shared_ptr rotate_left(avl_shared_ptr &node);
        avl_shared_ptr rotate_right(avl_shared_ptr &node);
        avl_shared_ptr do_balance(avl_shared_ptr &node);

        avl_shared_ptr deep_copy(const avl_shared_ptr &other);
        avl_shared_ptr try_alloc_node(const T &value, int height = 1) const;

        avl_shared_ptr _find(const T &value) const;

    private:
        avl_shared_ptr mp_root;
    };

    template <typename P>
    std::ostream &operator<<(std::ostream &os, const AVLTree<P> &tree)
    {
        if (tree.empty())
        {
            os << "{ empty }";
            return os;
        }

        os << "{ ";
        for (const auto &elem : tree)
            os << elem << " ";
        os << "}";
        return os;
    }

}

#include "BinarySearchTree_impl.hpp"
