#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec;

    int hui = *(vec.begin());
    
    std::cout << hui << std::endl;
    return 0;
}
