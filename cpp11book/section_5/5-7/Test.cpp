#include <iostream>
#include <thread>
#include <mutex>

struct Counter {
  int32_t value = 0;
  std::mutex mutex;

  void increment() {
    std::lock_guard<std::mutex> lock(mutex);
    ++value;
    std::cout << value << std::endl;
  }

  void decrement() {
    std::lock_guard<std::mutex> lock(mutex);
    --value;
    std::cout << value << std::endl;
  }

  int32_t get() {
    return value;
  }
};

Counter g_counter;

void Increments() {
  for (int32_t i = 0; i < 100; ++i) {
    g_counter.increment();
  }
}

void Decrements() {
  for (int32_t i = 0; i < 90; ++i) {
    g_counter.decrement();
  }
}

int main(void) {
  std::thread t1(Increments);
  std::thread t2(Decrements);

  t1.join();
  t2.join();

  return 0;
}