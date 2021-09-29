#include <iostream>
#include <functional>

class A {
  std::function<void()> callback_;
public:
  A(const std::function<void()>& f) : callback_(f) {}

  void notify(void) {
    callback_();        // 回调到上层
  }
};

class Foo {
public:
  void operator() () {
    std::cout << "Foo Called " << __FUNCTION__ << std::endl;
  }
};

int main() {
  Foo foo;
  A a(foo);
  a.notify();

  return 0;
}