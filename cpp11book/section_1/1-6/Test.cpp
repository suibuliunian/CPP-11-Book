#include <iostream>

template<typename T>
struct Foo {
  typedef T tpye;
};

template<typename T>
class A {
  // ...
};

int main()
{
  Foo<A<int>>::tpye foo;

  return 0;
}