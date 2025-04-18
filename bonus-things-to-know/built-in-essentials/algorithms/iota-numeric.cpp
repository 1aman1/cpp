#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> v1(10);

    std::iota(v1.begin(), v1.end(), 1);

    for (const auto itr : v1)
        std::cout << itr << " ";

    return 0;
}