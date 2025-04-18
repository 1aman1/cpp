#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

int main()
{

    std::vector<int> vint{1, 2, 3, 4, 5};

    std::cout << std::endl
              << std::accumulate(vint.begin(),
                                 vint.end(),
                                 0);

    std::cout << std::endl
              << std::accumulate(vint.begin(),
                                 vint.end(),
                                 1,
                                 std::multiplies<>());

    std::vector<std::string> vstr{"concat", "e", "nate"};

    std::cout << std::endl
              << std::accumulate(vstr.begin(),
                                 vstr.end(),
                                 std::string(""));

    struct fruit
    {
        std::string name;
        int price;
    };
    std::vector<fruit> vfruits{{"apple", 250}, {"orange", 100}};

    std::cout << std::endl
              << std::accumulate(begin(vfruits),
                                 end(vfruits),
                                 0,
                                 [](int accSum, const fruit &eachFruit)
                                 {
                                     return accSum + eachFruit.price;
                                 });

    std::cout << std::endl
              << std::accumulate(begin(vint),
                                 end(vint),
                                 0,
                                 [](int accSum, const int &eachValue)
                                 {
                                     return accSum + eachValue * eachValue;
                                 });

    std::unordered_map<std::string, int> scores = {{"Alice", 50}, {"Bob", 70}};

    std::cout << std::endl
              << std::accumulate(begin(scores),
                                 end(scores),
                                 0,
                                 [](int accSum, const auto &eachPair)
                                 {
                                     return accSum + eachPair.second;
                                 });

    return 0;
}