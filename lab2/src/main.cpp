#include <iostream>

#include <set>
#include "BinarySearchTree.h"
#include "ConstTreeIterator.h"

int main()
{
    // std::set<int> abober({1, 2, 3, 4, 5, 6});
    BinarySearchTree<int> tree({1, 2, 3, 0, 5, 6, 7, -8});

    // for (auto p : tree)
    // {
    //     std::cout << p << " ";
    // }
    // std::cout << std::endl;

    // auto p = tree.begin();
    // std::cout << *(tree.Erase(p)) << std::endl;

    auto f = tree.begin();
    auto s = tree.end();
    --s;
    --s;
    tree.Erase(f, s);

    for (auto p : tree)
    {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    return 0;
}
