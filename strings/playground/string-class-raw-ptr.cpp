#include <iostream>
#include <cstring>

using namespace std;

class myString
{
    char *coreBuf = nullptr;
    size_t bufferSize;

public:
    myString() : coreBuf(nullptr), bufferSize(0) {}

    myString(const char *buffer)
    {
        bufferSize = strlen(buffer);
        coreBuf = new char[bufferSize + 1];
        strcpy(coreBuf, buffer);
    }

    myString(const myString &cc) : myString(cc.c_str()) {}

    myString &operator=(const myString &buffer)
    {
        if (this != &buffer)
        {
            delete[] coreBuf;
            bufferSize = buffer.bufferSize;
            coreBuf = new char[bufferSize + 1];
            strcpy(coreBuf, buffer.coreBuf);
        }
        return *this;
    }

    myString(myString &&buffer)
    {
        coreBuf = buffer.coreBuf;
        buffer.coreBuf = nullptr;
        bufferSize = buffer.bufferSize;
        buffer.bufferSize = 0;
    }

    myString &operator=(myString &&buffer)
    {
        if (this != &buffer)
        {
            delete[] coreBuf;
            coreBuf = buffer.coreBuf;
            buffer.coreBuf = nullptr;
            bufferSize = buffer.bufferSize;
            buffer.bufferSize = 0;
        }
        return *this;
    }

    myString operator+(const myString &rhs)
    {
        myString tmp;
        tmp.bufferSize = this->bufferSize + rhs.bufferSize;
        tmp.coreBuf = new char[tmp.bufferSize + 1];
        strcpy(tmp.coreBuf, this->coreBuf ? this->coreBuf : "");
        strcat(tmp.coreBuf, rhs.coreBuf);
        return tmp;
    }

    myString operator+(const char *rhs)
    {
        myString tmp;
        tmp.bufferSize = this->bufferSize + strlen(rhs);
        tmp.coreBuf = new char[tmp.bufferSize + 1];
        strcpy(tmp.coreBuf, this->coreBuf ? this->coreBuf : "");
        strcat(tmp.coreBuf, rhs);
        return tmp;
    }

    bool operator==(const myString &rhs) const
    {
        return (strcmp(this->coreBuf, rhs.coreBuf) == 0);
    }

    bool operator!=(const myString &rhs) const
    {
        return !(*this == rhs);
    }

    char &operator[](size_t idx)
    {
        if (0 <= idx < bufferSize)
            return coreBuf[idx];
    }

    size_t size() const
    {
        return coreBuf ? bufferSize : 0;
    }

    const char *c_str() const
    {
        return coreBuf ? coreBuf : "";
    }

    ~myString()
    {
        __cleanup__();
    }

    void __cleanup__()
    {
        if (coreBuf != nullptr)
            delete[] coreBuf;
        bufferSize = 0;
    }
};

int main()
{

    myString obj("abc");
    cout << obj.c_str() << endl;

    myString s2(obj);
    cout << s2.c_str() << endl;

    myString s3 = s2;
    cout << s3.c_str() << endl;

    myString s4 = s2 + " def";
    cout << s4.c_str() << endl;

    myString s5 = s2 + s4;
    cout << s5.c_str() << endl;

    if (s3 == s2)
        cout << "==" << endl;
    if (s4 != s5)
        cout << "!=" << endl;

    return 0;
}