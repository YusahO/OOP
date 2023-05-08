#include <iostream>
#include "BinarySearchTree.hpp"

#include <vector>
#include <list>
using namespace MyBST;

int main()
{
    std::cout << "=== CONSTRUCTORS ===" << std::endl;
    {
        std::cout << "Empty constructor\n";
        BST<int> tree1;
        std::cout << "Tree1 " << tree1 << std::endl;
    }
    {
        std::cout << "Initializer list constructor\n";
        BST<int> tree1{1, 2, 3, 4, 5};
        std::cout << "Tree1 " << tree1 << std::endl;
    }
    {
        std::cout << "Move constructor\n";
        BST<int> tree1{1, 2, 3, 4, 5};
        std::cout << "Tree1 before move " << tree1 << std::endl;
        BST<int> tree2(std::move(tree1));
        std::cout << "--- MOVING ---" << std::endl;
        std::cout << "Tree1 after move " << tree1 << std::endl;
        std::cout << "Tree2 after move " << tree2 << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "Copy constructor\n";
        BST<int> tree1{1, 2, 3, 4, 5};
        BST<int> tree2(tree1);
        std::cout << "--- COPYING ---" << std::endl;
        std::cout << "Tree1 after copy " << tree1 << std::endl;
        std::cout << "Tree2 after copy " << tree2 << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "Move operator=\n";
        BST<int> tree1{1, 2, 3, 4, 5};
        BST<int> tree2;
        std::cout << "Tree1 before move " << tree1 << std::endl;
        std::cout << "Tree2 before move " << tree2 << std::endl;
        tree2 = std::move(tree1);
        std::cout << "--- MOVING ---" << std::endl;
        std::cout << "Tree1 after move " << tree1 << std::endl;
        std::cout << "Tree2 after move " << tree2 << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "Copy operator=\n";
        BST<int> tree1{1, 2, 3, 4, 5};
        BST<int> tree2;
        std::cout << "Tree1 before copy " << tree1 << std::endl;
        std::cout << "Tree2 before copy " << tree2 << std::endl;
        tree2 = tree1;
        std::cout << "--- COPYING ---" << std::endl;
        std::cout << "Tree1 after copy " << tree1 << std::endl;
        std::cout << "Tree2 after copy " << tree2 << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "Construct from std::vector\n";
        std::vector<int> vec_test{6, 5, 4, 3, 2, 1};
        BST<int> tree(vec_test);
        std::cout << tree << std::endl;
    }
    {
        std::cout << "Construct from std::vector::iterator\n";
        std::vector<int> vec_test{6, 5, 4, 3, 2, 1};
        BST<int> tree(vec_test.cbegin(), vec_test.cend());
        std::cout << tree << std::endl;
    }
    {
        std::cout << "Construct from std::list\n";
        std::list<int> list_test{6, 5, 4, 3, 2, 1};
        BST<int> tree(list_test);
        std::cout << tree << std::endl;
    }

    std::cout << "=== TREE OPERATIONS ===" << std::endl;
    {
        std::cout << "--- INSERTION ---" << std::endl;
        BST<int> tree;
        int arr[] = { 5, 3, 7, 2, 4, 6, 8, 1, 9 };
        for (size_t i = 0; i < sizeof(arr) / sizeof(int); ++i)
        {
            tree.insert(arr[i]);
        }
        std::cout << "tree: " << tree << std::endl;
        std::cout << "--- FIND ---" << std::endl;
        for (size_t i = 0; i < sizeof(arr) / sizeof(int); ++i)
        {
            std::cout << *tree.find(arr[i]) << " ";
        }
        std::cout << std::endl;
        std::cout << "--- SIZE ---" << std::endl;
        std::cout << tree << " size: " << tree.size() << std::endl;
        std::cout << "--- REMOVE ---" << std::endl;
        {
            auto tree_cp = tree;
            // std::cout << tree_cp << std::endl;
            auto beg_del = ++tree_cp.begin();
            auto end_del = --tree_cp.end();
            std::cout << "before del [" << *beg_del << ", " << *end_del << "): " << tree_cp << std::endl;
            tree_cp.erase(beg_del, end_del);
            std::cout << "after: " << tree_cp << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "=== ITERATORS ===" << std::endl;
    {
        std::cout << "--- ITERATORS not const tree ---" << std::endl;
        BST<int> a({ 1, 5, 2, 3, 4, 0, 6, 8, 7 });
        std::cout << "INIT A\n" << a << std::endl;

        std::cout << "For each const auto &elem with separate ' '\n";
        for (const auto &elem : a)
            std::cout << elem << " ";
        std::cout << std::endl;
        std::cout << "For each reverse auto &elem with separate ' '\n";
        for (auto rit = a.rbegin(); rit != a.rend(); ++rit)
            std::cout << *rit << " ";
        std::cout << "\nFor each const reverse auto &elem with separate ' '\n";
        const BST<int> &ca = a;
        for (auto rit = ca.rbegin(); rit != ca.rend(); ++rit)
            std::cout << *rit << " ";
        std::cout << std::endl;

        std::cout << "--- ITERATORS const tree ---" << std::endl;
        const BST<float> const_c{1, 5, 2, 3, 4, 0, 6, 8, 7};

        std::cout << "For each const auto &elem with separate ' '\n";
        for (const auto &elem : const_c)
            std::cout << elem << " ";
        std::cout << std::endl;
        std::cout << "For each const reverse auto &elem with separate ' '\n";
        for (auto it = const_c.rbegin(); it != const_c.rend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    std::cout << "=== EXCEPTIONS ===" << std::endl;
    {
        try
        {
            BST<int> test;
            *test.rbegin();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what();
        }
        try
        {
            BST<int> test;

            *test.rend();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what();
        }
        try
        {
            BST<int> test;

            *test.begin();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what();
        }
        // try
        // {
        //     BST<int> test;

        //     *test.end();
        // }

        // catch (const std::exception &e)
        // {
        //     std::cout << e.what();
        // }
        try
        {
            BST<int> test;
            test.insert(12);
            test.insert(12);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what();
        }

        std::cout << std::endl;
    }
    return 0;
}
