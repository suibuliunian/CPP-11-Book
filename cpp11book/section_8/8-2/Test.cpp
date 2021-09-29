#include <iostream>
#include <functional>

#include "Observer.hpp"

struct A {
  int a, b;
  void print(int a, int b) {
    std::cout << "A print " << a << " " << b << std::endl;
  }
};

void print(int a, int b) {
  std::cout << "print " << a << " " << b << std::endl;
}

int main() {
  Events<std::function<void(int, int)>> my_event;

  // 以函数的方式注册观察者
  auto key = my_event.Connect(print);

  A t;
  // lambda注册
  auto lambda_key = my_event.Connect([&t](int a, int b) {
    t.a = a;
    t.b = b;
    std::cout << "Lambda print" << a << " " << b << std::endl; });

  // std::function注册
  std::function<void(int, int)> func = std::bind(&A::print, &t, std::placeholders::_1, std::placeholders::_2);
  my_event.Connect(func);

  int a = 1, b = 2;
  my_event.Notify(a, b);

  my_event.Disconnect(key);

  return 0;
}