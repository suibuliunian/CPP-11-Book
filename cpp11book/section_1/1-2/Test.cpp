#include <iostream>

class Foo {
public:
  static int get(void)
  {
    std::cout << "int" << std::endl;
    return 0;
  }
};

class Bar {
public:
  static const char* get(void)
  {
    std::cout << "char" << std::endl;
    return "0";
  }
};

template <class A>
void func(void)
{
  auto val = A::get();

  //...
}

int main(void)
{
  func<Foo>();
  func<Bar>();

  return 0;
}