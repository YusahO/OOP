#pragma once

#include "common.hpp"
#include "TreeIterator.hpp"
#include "ReverseTreeIterator.hpp"

namespace MyBST
{

template <Comparable T>
class BST
{
public:
    friend class TreeIterator<T>;
    friend class ReverseTreeIterator<T>;

    using iterator = TreeIterator<T>;
    using reverse_iterator = ReverseTreeIterator<T>;
    using value_type = T;
    using size_type = size_t;

public: // TODO: change to private
    class TreeNode;
    using bst_shared_ptr = typename std::shared_ptr<TreeNode>;
    using bst_weak_ptr = typename std::weak_ptr<TreeNode>;

public:
    struct TreeNode
    {
        TreeNode();
        explicit TreeNode(T &&value);
        explicit TreeNode(const T &value);
        TreeNode(T &&value, const bst_shared_ptr &left, const bst_shared_ptr &right);
        TreeNode(const T &value, const bst_shared_ptr &left, const bst_shared_ptr &right);

        bool operator!=(const TreeNode &other) const; 

        T m_value;
        size_t m_height;
        bst_shared_ptr mp_left;
        bst_shared_ptr mp_right;
    };

public:
    BST();
    explicit BST(std::initializer_list<T> lst);

    template <Iterator Iter>
        requires Assignable<typename Iter::value_type, T>
    explicit BST(Iter first, Iter last);

    template <Container Con>
        requires Convertible<typename Con::value_type, T> && Assignable<typename Con::value_type, T>
    explicit BST(const Con &container);

    BST(const BST<T> &other);
    BST(BST<T> &&other);
    BST &operator=(const BST<T> &other);
    BST &operator=(BST<T> &&other);

    ~BST() = default;

    // вставка
    TreeIterator<T> insert(T &&value);
    TreeIterator<T> insert(const T &value);

    // поиск
    TreeIterator<T> find(const T &value);

    // удаление
    template <Iterator Iter>
        requires Assignable<typename Iter::value_type, T>
    TreeIterator<T> erase(Iter &pos);
    template <Iterator Iter>
        requires Assignable<typename Iter::value_type, T>
    TreeIterator<T> erase(Iter &first, Iter &last);
    bool erase(const T &value);

    void clean() noexcept;
    std::size_t size() const noexcept;

    TreeIterator<T> begin() const noexcept;
    TreeIterator<T> end() const noexcept;
    ReverseTreeIterator<T> rbegin() const noexcept;
    ReverseTreeIterator<T> rend() const noexcept;

    template <typename P>
    friend std::ostream &operator<<(std::ostream &os, const BST<P> &tree);

protected:
    bst_shared_ptr find_min(bst_shared_ptr &node) const;
    bst_shared_ptr remove_min(const bst_shared_ptr &node);
    size_t get_height(const bst_shared_ptr &node) const;
    size_t get_balance(const bst_shared_ptr &node) const;
    void fix_height(bst_shared_ptr &node);
    bst_shared_ptr rotate_left(bst_shared_ptr &node);
    bst_shared_ptr rotate_right(bst_shared_ptr &node);
    bst_shared_ptr do_balance(bst_shared_ptr &node);

    bst_shared_ptr get_root() const;
    std::size_t _size(const bst_shared_ptr &node) const;
    bst_shared_ptr _deep_copy(const bst_shared_ptr &other);
    std::pair<bst_shared_ptr, bool> _erase(const T &value);
    bst_shared_ptr _find(const T &value);
    std::ostream &_inorder(const bst_shared_ptr &node, std::ostream &os) const;

private:
    bst_shared_ptr mp_root = nullptr;
};

template <typename P>
std::ostream &operator<<(std::ostream &os, const BST<P> &tree)
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
