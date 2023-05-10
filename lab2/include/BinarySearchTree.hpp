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
            requires Convertible<typename Con::value_type, T> && Assignable<typename Con::value_type, T>
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
        std::size_t size() const;

        TreeIterator<T> begin() const;
        TreeIterator<T> end() const;
        ReverseTreeIterator<T> rbegin() const;
        ReverseTreeIterator<T> rend() const;

        // void Export(std::ostream &f)
        // {
        //     avl_shared_ptr tmp = mp_root;
        //     avl_export_to_dot(f);
        // }

        // void to_dot(avl_shared_ptr &tree, std::ostream &f)
        // {
        //     if (tree->mp_left)
        //     {
        //         f << "\"" << tree->m_value << ":" << tree->m_height << "\""
        //           << " -> "
        //           << "\"" << tree->mp_left->m_value << ":" << tree->mp_left->m_height << "\""
        //           << " [color = blue];\n";
        //     }

        //     if (tree->mp_right)
        //     {
        //         f << "\"" << tree->m_value << ":" << tree->m_height << "\""
        //           << " -> "
        //           << "\"" << tree->mp_right->m_value << ":" << tree->mp_right->m_height << "\""
        //           << " [color = red];\n";
        //     }
        // }

        // void apply_print(avl_shared_ptr p, std::ostream &arg)
        // {
        //     if (!p)
        //         return;

        //     apply_print(p->mp_left, arg);
        //     to_dot(p, arg);
        //     apply_print(p->mp_right, arg);
        // }

        // void avl_export_to_dot(std::ostream &f)
        // {
        //     if (!mp_root)
        //         return;

        //     f << "digraph " << "G" << " {\n";

        //     if (!mp_root->mp_left && !mp_root->mp_right)
        //     {
        //         f << mp_root->m_value << "\n";
        //     }

        //     apply_print(mp_root, f);

        //     f << "}\n";
        // }

        template <typename P>
        friend std::ostream &operator<<(std::ostream &os, const AVLTree<P> &tree);

    protected:
        size_t get_height(const avl_shared_ptr &node) const;
        int get_balance(const avl_shared_ptr &node) const;
        void fix_height(avl_shared_ptr &node);
        avl_shared_ptr rotate_left(avl_shared_ptr &node);
        avl_shared_ptr rotate_right(avl_shared_ptr &node);
        avl_shared_ptr do_balance(avl_shared_ptr &node);

        avl_shared_ptr deep_copy(const avl_shared_ptr &other);

        bool _erase(const T &value);
        avl_shared_ptr _find(const T &value) const;
        std::ostream &_inorder(const avl_shared_ptr &node, std::ostream &os) const;
        avl_shared_ptr try_alloc_node(const T &value, int height = 1) const;

    private:
        avl_shared_ptr mp_root = nullptr;
    };

    template <typename P>
    std::ostream &operator<<(std::ostream &os, const AVLTree<P> &tree)
    {
        os << "{ ";
        if (tree.mp_root)
        {
            tree._inorder(tree.mp_root, os);
        }
        else
        {
            std::cout << "empty ";
        }
        os << "}";
        return os;
    }

}

#include "BinarySearchTree_impl.hpp"
