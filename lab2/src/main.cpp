#include <iostream>

#include <set>
#include "BinarySearchTree.h"
#include "ConstTreeIterator.h"

int main()
{
    BinarySearchTree<int> tree({1,2,3,0,5,6,7,-8});
    std::cout << tree << std::endl;

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
