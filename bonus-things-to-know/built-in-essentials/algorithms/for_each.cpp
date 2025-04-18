#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

struct Item
{
    std::string name;
    int price;
};

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    int sum = 0;
    std::for_each(v.begin(), v.end(), [&sum](const int &x)
                  { sum += x; });
    std::cout << "Sum: " << sum << std::endl;

    int product = 1;
    std::for_each(v.begin(), v.end(), [&product](const int &x)
                  { product *= x; });
    std::cout << "Product: " << product << std::endl;

    std::vector<Item> items = {{"apple", 30}, {"banana", 20}};
    int totalPrice = 0;
    std::for_each(items.begin(), items.end(), [&totalPrice](const Item &item)
                  { totalPrice += item.price; });
    std::cout << "Total Price: " << totalPrice << std::endl;

    int sumOfSquares = 0;
    std::for_each(v.begin(), v.end(), [&sumOfSquares](int x)
                  { sumOfSquares += x * x; });
    std::cout << "Sum of Squares: " << sumOfSquares << std::endl;

    std::map<std::string, int> scores = {{"Alice", 50}, {"Bob", 70}};
    int totalScore = 0;
    std::for_each(scores.begin(), scores.end(), [&totalScore](const auto &pair)
                  { totalScore += pair.second; });
    std::cout << "Total Score: " << totalScore << std::endl;

    // 7. Boolean Count (count how many > 3)
    int countGreaterThanThree = 0;
    std::for_each(v.begin(), v.end(), [&countGreaterThanThree](int x)
                  {
        if (x > 3) ++countGreaterThanThree; });
    std::cout << "Count > 3: " << countGreaterThanThree << std::endl;

    return 0;
}
