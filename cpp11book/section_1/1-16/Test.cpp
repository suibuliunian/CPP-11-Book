#include <iostream>

void func(void)
{
  //...
}

struct Foo {
  void operator()(void)
  {
    //...
  }
};

struct Bar {
  using fr_t = void(*)(void);

  static void func(void)
  {
    //...
  }

  operator fr_t(void)
  {
    return func;
  }
};

struct A {
  int a_;

  void mem_func(void)
  {
    //...
  }
};

int main(void)
{
  void(*func_ptr)(void) = &func;  //1.函数指针
  func_ptr();

  Foo foo;  //2.仿函数
  foo();

  Bar bar;  //3.可转换为函数指针的类对象
  bar();

  void(A:: * mem_func_ptr)(void) = &A::mem_func;  //4.类成员函数指针
  int A::* mem_obj_ptr = &A::a_;  // 或者是类成员指针

  A aa;
  (aa.*mem_func_ptr)();
  aa.*mem_obj_ptr = 123;

  return 0;
}