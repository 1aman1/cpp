#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>

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

    cv_consumer.notify_one(); // wake one consumer
  }

  bool consume(int &value)
  {
    std::unique_lock<std::mutex> lock(mtx);

    cv_consumer.wait(lock, [this]
                     { return !buf.empty() || done.load(); });

    if (buf.empty() && done.load())
    {
      return false; // nothing more to consume
    }

    value = buf.front();
    buf.pop();

    cv_producer.notify_one(); // wake one producer
    return true;
  }

  void set_done()
  {
    {
      std::lock_guard<std::mutex> lock(mtx);
      done.store(true);
    }
    cv_consumer.notify_all(); // wake any waiting consumers
  }
};
