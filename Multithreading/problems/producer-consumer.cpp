#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>
#include <atomic>
#include <vector>

class BoundedBuffer
{
private:
  std::mutex mtx;
  std::condition_variable cv_producer;
  std::condition_variable cv_consumer;

  std::queue<int> buf;
  size_t capacity;

  std::atomic<bool> done{false};

public:
  BoundedBuffer(size_t cap) : capacity(cap) {}

  void produce(int value)
  {
    std::unique_lock<std::mutex> lock(mtx);
    cv_producer.wait(lock, [this]
                     { return buf.size() < capacity; });

    buf.push(value);
    std::cout << "Produced: " << value << "\n";

    cv_consumer.notify_one();
  }

  bool consume(int &value)
  {
    std::unique_lock<std::mutex> lock(mtx);

    cv_consumer.wait(lock, [this]
                     { return !buf.empty() || done.load(); });

    if (buf.empty() && done.load())
    {
      return false;
    }

    value = buf.front();
    buf.pop();
    std::cout << "  Consumed: " << value << "\n";

    cv_producer.notify_one();
    return true;
  }

  void set_done()
  {
    {
      std::lock_guard<std::mutex> lock(mtx);
      done.store(true);
    }
    cv_consumer.notify_all();
  }
};

void producer_thread(BoundedBuffer &buffer, int start, int count)
{
  for (int i = 0; i < count; ++i)
  {
    buffer.produce(start + i);
  }
}

void consumer_thread(BoundedBuffer &buffer)
{
  int val;
  while (buffer.consume(val))
  {
    // process(val);
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
  }
}

int main()
{
  BoundedBuffer buffer(5); // buffer capacity

  const int itemsPerProducer = 10;

  std::thread p1(producer_thread, std::ref(buffer), 100, itemsPerProducer);
  std::thread p2(producer_thread, std::ref(buffer), 200, itemsPerProducer);

  std::thread c1(consumer_thread, std::ref(buffer));
  std::thread c2(consumer_thread, std::ref(buffer));

  p1.join();
  p2.join();

  buffer.set_done(); // signal consumers to stop when done
  c1.join();
  c2.join();

  std::cout << "All done.\n";
  return 0;
}
