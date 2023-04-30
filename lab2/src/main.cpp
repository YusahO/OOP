#include <iostream>

#include <set>
#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> tree({4, 2, 5, 1, 3});
    tree.end();
    std::cout << tree.GetRoot() << "\n";
    // std::cout << "call begin\n";
    // TreeIterator<int> iter = tree.begin();
    // ++iter;
    // ++iter;
    // ++iter;
    // ++iter;
    // ++iter;
    for (auto it = tree.end(); it != tree.begin();)
    {
        std::cout << *(--it) << " "; // prints "7 6 5 4 3 2 1 "
    }
    return 0;
}
