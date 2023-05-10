#include <vector>
#include <iostream>
#include <set>

int main()
{
    std::set<int> abober{1, 2, 3, 4, 5, 6};
    auto it = abober.end();
    ++it;
    ++it;

    std::cout << (it == abober.end()) << "\n";
    return 0;
}