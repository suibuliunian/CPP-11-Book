#include <iostream>
#include <functional>

void func(void)
{
  std::cout << __FUNCTION__ << std::endl;
}

class Foo {
public:
  static int foo_func(int a)
  {
    std::cout << __FUNCTION__ << "(" << a << ") ->: "<< std::endl;
    return a;
  }
};

class Bar {
public:
  int operator()(int a)
  {
    std::cout << __FUNCTION__ << "(" << a << ") ->: "<< std::endl;
    return a;
  }
};

int main(void)
{
  // 绑定一个普通函数
  std::function<void(void)> fr1 = func;
  fr1();

  // 绑定一个类的静态成员函数
  std::function<int(int)> fr2 = Foo::foo_func;
  fr2(123);

  // 绑定一个仿函数
  Bar bar;
  std::function<int(int)> fr3 = bar;
  fr3(123);

  return 0;
}
