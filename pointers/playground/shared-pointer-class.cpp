#include <iostream>
using namespace std;

template <class T>
class mySharedPtr
{
private:
    typedef unsigned int uint;

    T *rawPtr = nullptr;
    uint *refCount = nullptr;

public:
    mySharedPtr() : rawPtr(nullptr), refCount(new uint(0)) { cout << "0-arg ctor\n"; }
    mySharedPtr(T *ptr) : rawPtr(ptr), refCount(new uint(1)) { cout << "1-arg ctor\n"; }

    mySharedPtr(const mySharedPtr &rhs) : rawPtr(rhs.rawPtr), refCount(rhs.refCount)
    {
        if (rhs.rawPtr != nullptr)
        {
            ++(*(this->refCount));
        }
    }

    mySharedPtr(mySharedPtr &&dyingRhs) : rawPtr(dyingRhs.rawPtr), refCount(dyingRhs.refCount)
    {
        dyingRhs.rawPtr = dyingRhs.refCount = nullptr;
    }

    mySharedPtr &operator=(const mySharedPtr &rhs)
    {
        if (this != &rhs)
        {
            __cleanup__();

            this->rawPtr = rhs.rawPtr;
            this->refCount = rhs.refCount;

            if (rhs.rawPtr != nullptr)
            {
                ++(*(this->refCount));
            }
        }

        return *this;
    }

    mySharedPtr &operator=(mySharedPtr &&dyingRhs)
    {
        if (this != &dyingRhs)
        {
            __cleanup__();

            this->rawPtr = dyingRhs.rawPtr;
            this->refCount = dyingRhs.refCount;

            dyingRhs.rawPtr = dyingRhs.refCount = nullptr;
        }

        return *this;
    }

    T *get() const
    {
        return this->rawPtr;
    }

    uint getCount() const
    {
        return *(this->refCount);
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
        if (this->rawPtr != nullptr && this->refCount != nullptr)
        {
            --(*(this->refCount));
            if (*(this->refCount) == 0)
            {
                delete this->rawPtr;
                delete this->refCount;
            }
        }
    }

    ~mySharedPtr()
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
    mySharedPtr<node> obj;
    cout << obj.getCount() << endl;

    mySharedPtr<node> obj1(new node());
    cout << obj1.getCount() << endl;

    mySharedPtr<node> obj2(obj1);
    cout << obj2.getCount() << endl;

    mySharedPtr<node> obj3 = obj2;
    cout << obj3.getCount() << endl;
    cout << obj3->data << endl;

    mySharedPtr<node> obj4 = obj3;
    cout << obj4->data << endl;

    return 0;
}