#include <iostream>
#include <thread>
#include <mutex>

struct Complex {
  std::mutex mutex;
  int i;

  Complex() : i(1) {}

  void mul(int x)
  {
    std::lock_guard<std::mutex> lock(mutex);
    i *= x;
    std::cout << "mul" << std::endl;
  }

  void div(int x)
  {
    std::lock_guard<std::mutex> lock(mutex);
    i /= x;
    std::cout << "div" << std::endl;
  }

  void both(int x, int y)
  {
    std::lock_guard<std::mutex> lock(mutex);
    mul(x);
    div(y);
    std::cout << "both" << std::endl;
  }
};

int main(void)
{
  Complex complex;

  complex.both(32, 23);

  std::cout << complex.i << std::endl;

  return 0;
}