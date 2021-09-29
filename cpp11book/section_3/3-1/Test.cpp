#include <iostream>
#include <type_traits>
#include <memory>

template <class T>
struct Construct {
  // 移除可能的引用
  typedef typename std::remove_reference<T>::type U;

  Construct() : m_ptr(new U) {}

  // 添加左值引用
  typename std::add_lvalue_reference<U>::type Get() const
  {
    *m_ptr = 100;
    return *m_ptr.get();
  }

private:
  std::unique_ptr<U> m_ptr;
};

int main(void)
{
  Construct<int> c;
  int a = c.Get();

  std::cout << a << std::endl;

  return 0;
}