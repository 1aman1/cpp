#include <iostream>

class zee5
{
public:
    int content_zee5;
    std::string genre;
    zee5(int c, std::string t) : content_zee5(c), genre(t) {}
};

class prime
{
public:
    std::string genre;
    int content_prime;

    prime(zee5 tmp) // 1 arg constructor
    {
        zee5(tmp.content_zee5, tmp.genre);
    }
};

int main()
{
    zee5 Zuser(1, "run");

    prime Primeuser = Zuser;



    return 0;
}