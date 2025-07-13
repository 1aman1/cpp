#include <boost/asio.hpp>
#include <iostream>
#include <thread>

void print_handler(int id)
{
  std::cout << "Handler " << id << " executed on thread "
            << std::this_thread::get_id() << "\n";
}

int main()
{
  boost::asio::io_context io_context;

  boost::asio::strand<boost::asio::io_context::executor_type> strand(io_context.get_executor());

  for (int i = 0; i < 5; ++i)
  {
    boost::asio::post(strand, [i]()
                      { print_handler(i); });
  }

  std::cout << "post handlers";

  std::thread t1([&]()
                 { io_context.run(); });
  std::thread t2([&]()
                 { io_context.run(); });

  t1.join();
  t2.join();

  return 0;
}
