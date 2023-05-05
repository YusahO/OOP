#pragma once

#include "common.hpp"
#include "TreeIterator.hpp"
#include "ReverseTreeIterator.hpp"

#include "TreeNode.hpp"

namespace MyBST {

    template <Comparable T>
    class BinarySearchTree
    {
    public:
        using iterator = TreeIterator<T>;
        using value_type = T;

    public:
        BinarySearchTree();
        explicit BinarySearchTree(std::initializer_list<T> lst);

        template<Container Con>
        explicit BinarySearchTree(const Con &container);

        BinarySearchTree(const BinarySearchTree<T> &other);
        BinarySearchTree(BinarySearchTree<T> &&other);
        BinarySearchTree &operator=(const BinarySearchTree<T> &other);
        BinarySearchTree &operator=(BinarySearchTree<T> &&other);

        virtual ~BinarySearchTree() = default;

        // вставка
        virtual TreeIterator<T> Insert(T &&value);
        virtual TreeIterator<T> Insert(const T &value);

        // поиск
        TreeIterator<T> Find(const T &value);

        // удаление
        template <class Iter>
        TreeIterator<T> Erase(Iter &pos);
        template <class Iter>
        TreeIterator<T> Erase(Iter &first, Iter &last);
        bool Erase(const T &value);

        BSTSharedPtr<T> GetRoot() const;

        virtual void Clean() noexcept;
        std::size_t size() const noexcept;

        TreeIterator<T> begin() const noexcept;
        TreeIterator<T> end() const noexcept;
        ReverseTreeIterator<T> rbegin() const noexcept;
        ReverseTreeIterator<T> rend() const noexcept;

        template <typename P>
        friend std::ostream &operator<<(std::ostream &os, const BinarySearchTree<P> &tree);

    protected:
        std::size_t _Size(const BSTSharedPtr<T> &node);
        BSTSharedPtr<T> _DeepCopy(const BSTSharedPtr<T> &other);
        std::pair<BSTSharedPtr<T>, bool> _Erase(const T &value);
        BSTSharedPtr<T> _Find(const T &value);
        std::ostream &_Inorder(const BSTSharedPtr<T> &node, std::ostream &os) const;

    private:
        BSTSharedPtr<T> mp_root = nullptr;
    };

    template <typename P>
    std::ostream &operator<<(std::ostream &os, const BinarySearchTree<P> &tree)
    {
        os << "{ ";
        if (tree.mp_root)
        {
            tree._Inorder(tree.mp_root, os);
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
