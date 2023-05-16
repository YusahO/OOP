#pragma once

#include "common.hpp"
#include "BaseTree.hpp"
#include "TreeIterator.hpp"
#include "ReverseTreeIterator.hpp"

#include <fstream>
#include <vector>

namespace MyBST
{

    template <TreeElement T>
    class BSTree : public BaseTree
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
        using bst_shared_ptr = typename std::shared_ptr<TreeNode>;
        using bst_weak_ptr = typename std::weak_ptr<TreeNode>;

    private:
        class TreeNode : public std::enable_shared_from_this<TreeNode>
        {
        public:
            TreeNode();
            explicit TreeNode(T &&value);
            explicit TreeNode(const T &value);

            const T &get_value() const noexcept;
            [[nodiscard]] const bst_shared_ptr &get_left() const noexcept;
            [[nodiscard]] const bst_shared_ptr &get_right() const noexcept;

            void set_value(const T &value) noexcept;
            void set_left(const bst_shared_ptr &node) noexcept;
            void set_right(const bst_shared_ptr &node) noexcept;

            [[nodiscard]] bst_shared_ptr get_leftmost() noexcept;
            [[nodiscard]] bst_shared_ptr get_rightmost() noexcept;

            [[nodiscard]] bst_shared_ptr search(const T &value) const;
            bool insert(const bst_shared_ptr &node);

            void search_fill_stack(std::stack<bst_weak_ptr> &stack, const T &value) const;

            void leftmost_fill_stack(std::stack<bst_weak_ptr> &stack) noexcept;
            void rightmost_fill_stack(std::stack<bst_weak_ptr> &stack) noexcept;

            bool operator!=(const TreeNode &other) const;

        private:
            bst_shared_ptr get_this();

        private:
            T m_value;
            bst_shared_ptr mp_left;
            bst_shared_ptr mp_right;
        };

    public:
        BSTree();
        BSTree(std::initializer_list<T> lst);
        BSTree(const T *const arr, const size_t size);

        template <Iterator Iter>
            requires Assignable<typename Iter::value_type, T>
        explicit BSTree(Iter first, Iter last);

        template <Container Con>
            requires Convertible<typename Con::value_type, T> && Assignable<typename Con::value_type, T>
        explicit BSTree(const Con &container);

        explicit BSTree(const BSTree<T> &other);
        BSTree(BSTree<T> &&other) noexcept;
        BSTree &operator=(const BSTree<T> &other);
        BSTree &operator=(BSTree<T> &&other) noexcept;
        BSTree &operator=(std::initializer_list<T> lst);

        BSTree &operator+=(const BSTree<T> &other);
        BSTree &operator-=(const BSTree<T> &other);
        BSTree &operator^=(const BSTree<T> &other);
        BSTree &operator&=(const BSTree<T> &other);

        [[nodiscard]] BSTree operator+(const BSTree<T> &other) const;
        [[nodiscard]] BSTree operator-(const BSTree<T> &other) const;
        [[nodiscard]] BSTree operator^(const BSTree<T> &other) const;
        [[nodiscard]] BSTree operator&(const BSTree<T> &other) const;

        ~BSTree() = default;

        bool operator==(const BSTree &other) const;

        // вставка
        template<typename...Args>
        bool insert(Args&&... args);
        bool insert(const T &value);

        // поиск
        TreeIterator<T> find(const T &value) const;
        bool contains(const T &value) const;

        // удаление
        template <Iterator Iter>
            requires Assignable<typename Iter::value_type, T>
        bool erase(Iter pos);
        bool erase(const T &value);

        void balance();

        void clear() noexcept;
        bool empty() const noexcept override;
        std::size_t size() const noexcept override;

        [[nodiscard]] BSTree get_union(const BSTree &other) const;
        [[nodiscard]] BSTree get_intersection(const BSTree &other) const;
        [[nodiscard]] BSTree get_difference(const BSTree &other) const;
        [[nodiscard]] BSTree get_sym_difference(const BSTree &other) const;

        TreeIterator<T> begin() const;
        TreeIterator<T> end() const;
        ReverseTreeIterator<T> rbegin() const;
        ReverseTreeIterator<T> rend() const;

        template <typename P>
        friend std::ostream &operator<<(std::ostream &os, const BSTree<P> &tree);

    protected:
        std::vector<bst_shared_ptr> ravel() const;
        bst_shared_ptr deep_copy(const bst_shared_ptr &other);
        bst_shared_ptr try_alloc_node(T &&value) const;

        bst_shared_ptr _find(const T &value) const;

    private:
        bst_shared_ptr mp_root;
    };
}

#include "BSTree_impl.hpp"
