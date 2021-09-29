#include <iostream>
#include <string>
#include "Singleton.hpp"

struct A {
  A(const std::string&) {
    std::cout << "lvalue A" << std::endl;
  };

  A(std::string&& x) {
    std::cout << "rvalue A" << std::endl;
  }
};

struct B {
  B(const std::string&) {
    std::cout << "lvalue B" << std::endl;
  };

  B(std::string&& x) {
    std::cout << "rvalue B" << std::endl;
  }
};

struct C {
  C(int x, double y) {};

  void Fun() {
    std::cout << "test C" << std::endl;
  }
};

int main() {
  // 8-1
  // Singleton<A>::Instance();
  // Singleton<B>::Instance(1);
  // Singleton<C>::Instance(1, 3.14);

  // Singleton<A>::DestroyInstance();
  // Singleton<B>::DestroyInstance();
  // Singleton<C>::DestroyInstance();

  // 8-2
  std::string str="bb";
  Singleton<A>::Instance(str);
  Singleton<B>::Instance(std::move(str));
  // Singleton<B>::Instance(str);
  Singleton<C>::Instance(1, 3.14);
  Singleton<C>::GetInstance()->Fun();

  Singleton<A>::DestroyInstance();
  Singleton<B>::DestroyInstance();
  Singleton<C>::DestroyInstance();
}