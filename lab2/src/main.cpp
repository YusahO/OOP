#include <iostream>
#include "BSTree.hpp"

#include <vector>
#include <list>
using namespace MyBST;

struct TestObj
{
    TestObj() : test(0) {}
    TestObj(int test) : test(test) {}
    int test;
    const auto operator<=>(const TestObj &other) const
    {
        return test <=> other.test;
    }

    const bool operator==(const TestObj &other) const
    {
        return test == other.test;
    }
};

struct ManyArgsTestObj
{
    ManyArgsTestObj(int test1, float test2) : test1(test1), test2(test2) {}

    int test1;
    float test2;

    const auto operator<=>(const ManyArgsTestObj &other) const
    {
        return test1 <=> other.test1;
    }

    const bool operator==(const ManyArgsTestObj &other) const
    {
        return test1 == other.test1;
    }
};

int main()
{
    std::cout << "=== CONSTRUCTORS ===" << std::endl;
    {
        std::cout << "\nEmpty constructor\n";
        BSTree<int> tree1;
        std::cout << "Tree1 " << tree1 << std::endl;
    }
    {
        std::cout << "\nInitializer list constructor\n";
        BSTree<int> tree1{1, 2, 3, 4, 5};
        std::cout << "Tree1 " << tree1 << std::endl;
    }
    {
        std::cout << "\nMove constructor\n";
        BSTree<int> tree1{1, 2, 3, 4, 5};
        std::cout << "Tree1 before move " << tree1 << std::endl;
        BSTree<int> tree2(std::move(tree1));
        std::cout << "--- MOVING ---" << std::endl;
        std::cout << "Tree1 after move " << tree1 << std::endl;
        std::cout << "Tree2 after move " << tree2 << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "\nCopy constructor\n";
        BSTree<int> tree1{1, 2, 3, 4, 5};
        BSTree<int> tree2(tree1);
        std::cout << "--- COPYING ---" << std::endl;
        std::cout << "Tree1 after copy " << tree1 << std::endl;
        std::cout << "Tree2 after copy " << tree2 << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "\nMove operator=\n";
        BSTree<int> tree1{1, 2, 3, 4, 5};
        BSTree<int> tree2;
        std::cout << "Tree1 before move " << tree1 << std::endl;
        std::cout << "Tree2 before move " << tree2 << std::endl;
        tree2 = std::move(tree1);
        std::cout << "--- MOVING ---" << std::endl;
        std::cout << "Tree1 after move " << tree1 << std::endl;
        std::cout << "Tree2 after move " << tree2 << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "\nCopy operator=\n";
        BSTree<int> tree1{1, 2, 3, 4, 5};
        BSTree<int> tree2;
        std::cout << "Tree1 before copy " << tree1 << std::endl;
        std::cout << "Tree2 before copy " << tree2 << std::endl;
        tree2 = tree1;
        std::cout << "--- COPYING ---" << std::endl;
        std::cout << "Tree1 after copy " << tree1 << std::endl;
        std::cout << "Tree2 after copy " << tree2 << std::endl;
    }
    {
        std::cout << "\nConstruct from std::vector\n";
        std::vector<int> vec_test{6, 5, 4, 3, 2, 1};
        BSTree<int> tree(vec_test);
        std::cout << tree << std::endl;
    }
    {
        std::cout << "\nConstruct from std::vector::iterator\n";
        std::vector<int> vec_test{6, 5, 4, 3, 2, 1};
        BSTree<int> tree(vec_test.cbegin(), vec_test.cend());
        std::cout << tree << std::endl;
    }
    {
        std::cout << "\nConstruct from std::list\n";
        std::list<int> list_test{6, 5, 4, 3, 2, 1};
        BSTree<int> tree(list_test);
        std::cout << tree << std::endl;
    }

    {
        std::cout << "\nCustom object\n";
        BSTree<TestObj> tree;
        tree.insert(TestObj(12));
        tree.insert(TestObj(13));
        tree.insert(TestObj(14));
        for (auto &obj : tree)
        {
            std::cout << obj.test << " ";
        }
        std::cout << std::endl;
    }

    {
        std::cout << "\nCustom object with many args\n";
        BSTree<ManyArgsTestObj> tree;
        tree.insert(12, 12);
        tree.insert(13, 13.f);
        tree.insert(14, 14.f);
        for (auto &obj : tree)
        {
            std::cout << obj.test1 << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== TREE OPERATIONS ===" << std::endl;
    {
        std::cout << "\n--- INSERTION ---" << std::endl;
        BSTree<int> tree;
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        for (size_t i = 0; i < sizeof(arr) / sizeof(int); ++i)
        {
            std::cout << "insert " << i + 1 << ": " << (tree.insert(arr[i]) ? "true" : "false") << "\n";
        }
        std::cout << "tree: " << tree << std::endl;
        std::cout << "\n--- FIND ---" << std::endl;
        for (size_t i = 0; i < sizeof(arr) / sizeof(int); ++i)
        {
            std::cout << *tree.find(arr[i]) << " ";
        }
        std::cout << std::endl;
        std::cout << "\n--- SIZE ---" << std::endl;
        std::cout << tree << " size: " << tree.size() << std::endl;
        std::cout << "\n--- REMOVE ---" << std::endl;
        {
            auto tree_cp = BSTree(tree);
            std::cout << "before del of 6: " << tree_cp << std::endl;
            std::cout << "result: " << (tree_cp.erase(6) ? "true" : "false") << std::endl;
            std::cout << "after: " << tree_cp << std::endl;
        }
        {
            auto tree_cp = BSTree(tree);
            std::cout << "before del of 10 (not in tree): " << tree_cp << std::endl;
            std::cout << "result: " << (tree_cp.erase(10) ? "true" : "false") << std::endl;
            std::cout << "after: " << tree_cp << std::endl;
        }
    }
    {
        std::cout << "\n--- BALANCING ---" << std::endl;
        BSTree<int> tree{1, 2, 3, 4, 5, 6};
        std::cout << "Initial tree: " << tree << '\n';
        tree.balance();
        std::cout << "Tree after balancing: " << tree << '\n';
    }

    {
        std::cout << "\n--- THEORETICAL MULTIPLE OPERATIONS ---" << std::endl;
        BSTree<int> a{1, 2, 3, 4, 5}, b{ 3, 4, 5, 6, 7 };
        std::cout << "Tree a: " << a << std::endl;
        std::cout << "Tree b: " << b << std::endl;
        std::cout << std::endl;
        {
            BSTree<int> a_cp = BSTree(a);
            BSTree<int> b_cp = BSTree(b);
            std::cout << "intersection: " << a_cp.get_intersection(b_cp) << std::endl;
        }
        {
            BSTree<int> a_cp = BSTree(a);
            BSTree<int> b_cp = BSTree(b);
            std::cout << "difference: " << a_cp.get_difference(b_cp) << std::endl;
        }
        {
            BSTree<int> a_cp = BSTree(a);
            BSTree<int> b_cp = BSTree(b);
            std::cout << "sym-difference: " << a_cp.get_sym_difference(b_cp) << std::endl;
        }
        {
            BSTree<int> a_cp = BSTree(a);
            BSTree<int> b_cp = BSTree(b);
            std::cout << "union: " << a_cp.get_union(b_cp) << std::endl;
        }
    }

    std::cout << "\n=== ITERATORS ===" << std::endl;
    {
        std::cout << "\nITERATORS empty tree" << std::endl;
        BSTree<int> tree;
        std::cout << "begin() == end(): " << (tree.begin() == tree.end()) << std::endl;
    }
    {
        std::cout << "\n--- ITERATORS not const tree ---" << std::endl;
        BSTree<int> a{1, 5, 2, 3, 4, 0, 6, 8, 7};
        std::cout << "INIT A\n"
            << a << std::endl;
        std::cout << "\nFor loop with iterator\n";
        for (auto elem = a.begin(); elem != a.end(); ++elem)
            std::cout << *elem << " ";
        std::cout << std::endl;
        std::cout << "\nFor each loop with const iterator&\n";
        for (const auto &elem : a)
            std::cout << elem << " ";
        std::cout << std::endl;
        std::cout << "\nFor loop with const reverse iterator&\n";
        for (auto rit = a.rbegin(); rit != a.rend(); ++rit)
            std::cout << *rit << " ";
        std::cout << std::endl;
        std::cout << "\nFor each const reverse auto &elem with separate ' '\n";
        const BSTree<int> &ca = a;
        for (auto rit = ca.rbegin(); rit != ca.rend(); ++rit)
            std::cout << *rit << " ";
        std::cout << std::endl;

        std::cout << "\n--- ITERATORS const tree ---" << std::endl;
        const BSTree<float> const_c{1, 5, 2, 3, 4, 0, 6, 8, 7};

        std::cout << "For each loop with const iterator&\n";
        for (const auto &elem : const_c)
            std::cout << elem << " ";
        std::cout << std::endl;
        std::cout << "\nFor loop with const reverse iterator&\n";
        for (auto it = const_c.rbegin(); it != const_c.rend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        {
            std::cout << "\nITERATORS operator*" << std::endl;
            BSTree<int> tree{1, 2, 3, 4, 5, 6};
            std::cout << "tree: " << tree << "\n";
            auto it = tree.begin();
            std::cout << "*tree.begin(): " << *it << "\n";
        }
        {
            std::cout << "\nINCREMENT end()\n";
            BSTree<int> tree{1, 2, 3, 4, 5};
            auto it = tree.end();
            auto it2 = it;
            ++it2;
            std::cout << "it == ++it: " << (it == it2 ? "true" : "false") << std::endl;
        }
        {
            std::cout << "\nDECREMENT rend()\n";
            BSTree<int> tree{1, 2, 3, 4, 5};
            auto it = tree.rend();
            auto it2 = it;
            --it2;
            std::cout << "it == --it: " << (it == it2 ? "true" : "false") << std::endl;
        }
    }

    std::cout << "\n=== EXCEPTIONS ===\n" << std::endl;
    {
        std::cout << "--- Try to dereference rend() iterator ---\n";
        try
        {
            BSTree<int> test{1, 2, 3, 4, 5};
            *test.rend();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what();
        }
        std::cout << std::endl;

        std::cout << "--- Try to dereference end() iterator ---\n";
        try
        {
            BSTree<int> test{1, 2, 3, 4, 5};
            *test.end();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what();
        }
        std::cout << std::endl;

        std::cout << "--- Try to dereference iterator to empty object ---\n";
        try
        {
            BSTree<int> test;
            *test.begin();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what();
        }
        std::cout << std::endl;
    }
    return 0;
}
