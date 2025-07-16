#include <iostream>
#include <string.h>

using namespace std;

class myString
{
    char *coreBuf = nullptr;
    size_t size;

public:
    myString() : coreBuf(nullptr), size(0) {}

    myString(const char *buffer)
    {
        size = strlen(buffer);
        coreBuf = new char[size + 1];
        strncpy(coreBuf, buffer, size);
    }

    myString(const myString &rhs)
    {
        size = rhs.size;
        coreBuf = new char[size + 1];
        strncpy(coreBuf, rhs.coreBuf, size);
    }

    myString &operator=(const myString &rhs)
    {
        size = rhs.size;
        coreBuf = new char[size + 1];
        strncpy(coreBuf, rhs.coreBuf, size);

        return *this;
    }

    myString(myString &&dyingRhs)
    {
        size = dyingRhs.size;
        coreBuf = dyingRhs.coreBuf;
        dyingRhs.coreBuf = nullptr;
    }

    myString &operator=(myString &&dyingRhs)
    {
        size = dyingRhs.size;
        coreBuf = dyingRhs.coreBuf;
        dyingRhs.coreBuf = nullptr;

        return *this;
    }

    myString operator+(const myString &rhs)
    {
        myString tmp;

        tmp.size = this->size + rhs.size;
        tmp.coreBuf = new char[tmp.size + 1];

        strncpy(tmp.coreBuf, this->coreBuf, this->size);
        strncpy(tmp.coreBuf + this->size, rhs.coreBuf, rhs.size);

        return tmp;
    }

    int getSize() const
    {
        return size;
    }

    const char *c_str() const
    {
        return coreBuf;
    }

    ~myString()
    {
        __cleanup__();
    }

    void __cleanup__()
    {
        if (coreBuf != nullptr)
            delete[] coreBuf;
        size = 0;
    }
};

std::ostream &operator<<(std::ostream &cout, const myString &obj)
{
    cout << obj.c_str();
    return cout;
}

int main()
{

    myString obj("myString");

    cout << obj.c_str() << endl;

    myString s2(obj);
    cout << s2.c_str() << endl;

    myString s3 = s2;
    cout << s3.c_str() << endl;

    myString s4 = s2 + " impl";
    cout << s4.c_str() << endl;

    return 0;
}