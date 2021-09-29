#include <iostream>
#include <vector>

// template <class ContainerT>
// class Foo {
//   typename ContainerT::iterator it_;  //类型定义可能有问题
//   //这样貌似没什么问题，但是当上下文传入一个const容器类型，编译器会报错
//   //原因是因为ContainerT::iterator并不能包括所有的迭代器类型，因此当ContainerT是一个const类型时，
//   //应当使用 const_iterator
// public:
//   void func(ContainerT& container)
//   {
//     it_ = container.begin();
//   }

//   //...
// };

// 传入const使用此类
// template <class ContainerT>
// class Foo {
//   typename ContainerT::const_iterator it_;
// public:
//   void func(ContainerT& container)
//   {
//     it_ = container.begin();
//   }

//   //...
// };

// 使用decltype
template <class ContainerT>
class Foo {
  decltype(ContainerT().begin()) it_;
public:
  void func(ContainerT& container)
  {
    it_ = container.begin();
  }

  //...
};

int main(void)
{
  typedef const std::vector<int> container_t;
  container_t arr;

  Foo<container_t> foo;
  foo.func(arr);

  return 0;
}