#define _CRT_SECURE_NO_WARNINGS

#include "Timer.hpp"

#include <chrono>
#include <iostream>
#include <iomanip>
#include <ctime>

void fun() {
  std::cout << "hello world" << std::endl;
}

void Test() {
  std::cout << "\nTest()\n";

  Timer t;  // 开始计时
  fun();

  std::cout << t.elapsed() << " ms" << std::endl;                              // 打印fun函数耗时多少毫秒
  std::cout << t.elapsed_nano() << " ns" << std::endl;                  // 打印纳秒
  std::cout << t.elapsed_micro() << " us" << std::endl;                // 打印微秒
  std::cout << t.elapsed_seconds() << " s" << std::endl;           // 打印秒
  std::cout << t.elapsed_minutes() << " m" << std::endl;           // 打印分钟
  std::cout << t.elapsed_hours() << " h" << std::endl;               // 打印小时
}


int main(void)
{
  Test();

  return 0;
}