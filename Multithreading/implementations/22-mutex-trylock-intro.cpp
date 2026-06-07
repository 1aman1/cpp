#include <iostream>
#include <thread>
#include <mutex>

int wallet = 0;
std::mutex mtx;

void addMoney()
{
    for (int i = 0; i < 100; ++i)
    {
        if (mtx.try_lock())
        {
            ++wallet;
            std::cout << std::this_thread::get_id();
            mtx.unlock();
        }
    }
}

int main()
{
    std::cout << wallet << "\n";

    std::thread t1(addMoney);
    std::thread t2(addMoney);

    std::cout << "pre main thread \n";

    t1.join();
    t2.join();

    std::cout << wallet << "\n";
    std::cout << "post main thread\n";

    return 0;
}
