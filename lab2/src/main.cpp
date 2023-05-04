#include <iostream>

#include <set>
#include "BinarySearchTree.h"

int main()
{
    // std::set<int> abober{4, 2, 5, 1, 3};
    // auto st = abober.begin();
    // auto en = abober.end();

    // auto de = abober.erase(++st, en);
    // std::cout << "Next After Deleted: " << *(de) << "\n";

    // for (auto &p : abober)
    //     std::cout << p << " ";
    // std::cout << "\n";

    MyBST::BinarySearchTree<int> tree{4, 2, 5, 1, 3};
    // std::cout << "Inserted " << *(tree.Insert(8)) << "\n";

    auto iter = tree.begin();
    auto end = tree.end();
    auto aboboe = tree.Erase(++iter, --end);
    // std::cout << "Next After Deleted: " << *(aboboe) << "\n";

    std::cout << tree.begin() << "\n";
    end = tree.end();
    for (auto &p : tree)
    {
        std::cout << p << " "; // prints "7 6 5 4 3 2 1 "
    }
    std::cout << std::endl;
    return 0;
}
