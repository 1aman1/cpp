#include <iostream>
using namespace std;

template <class T>
class myUniquePtr
{
private:
    T *rawPtr;

public:
    // myUniquePtr() : rawPtr(nullptr) { cout << "0-arg ctor\n"; } // no issue with it, just a design call
    myUniquePtr(T *ptr = nullptr) : rawPtr(ptr) { cout << "1-arg ctor\n"; }

    myUniquePtr(const myUniquePtr &tmp) = delete;
    myUniquePtr &operator=(const myUniquePtr &tmp) = delete;

    myUniquePtr(myUniquePtr &&dyingRhs) : rawPtr(dyingRhs.rawPtr)
    {
        dyingRhs.rawPtr = nullptr;
    }

    myUniquePtr &operator=(myUniquePtr &&dyingRhs)
    {
        if (this != dyingRhs)
        {
            __cleanup__();

            this->rawPtr = dyingRhs.rawPtr;
            
            dyingRhs.rawPtr = nullptr;
        }

        return *this;
    }

    T *get() const
    {
        return this->rawPtr;
    }

    T *operator->() const
    {
        return rawPtr;
    }

    T &operator*() const
    {
        return *(this->rawPtr);
    }

    void __cleanup__()
    {
        if (rawPtr != nullptr)
            delete rawPtr;
    }

    ~myUniquePtr()
    {
        __cleanup__();
    }
};

struct node
{
    int data;
    node() : data(200) {}
};

int main()
{
    myUniquePtr<node> obj(new node);
    cout << obj->data << endl;

    myUniquePtr<node> obj1(move(obj));
    cout << obj1->data << endl;

    myUniquePtr<node> obj2 = move(obj1);
    cout << obj2->data << endl;

    return 0;
}