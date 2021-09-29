#include <iostream>
#include <thread>
#include <utility>
#include <future>
#include <vector>

int func(int x) { return x + 2; }

int main(void)
{
	std::packaged_task<int(int)> tsk(func);
	std::future<int> fut = tsk.get_future();  //获取future

	std::thread(std::move(tsk), 2).detach(); // task作为线程函数

	int value = fut.get();  // 等待task完成并获取结果
	std::cout << "The result is " << value << ".\n";

  // std::future是不能复制的，不能放到容器中，需要用shared_future
	std::vector<std::shared_future<int>> v;
	std::shared_future<int> f = std::async(std::launch::async, [](int a, int b){return a + b; }, 2, 3);

	v.push_back(f);
	std::cout << "The shared_future result is " << v.at(0).get() << std::endl;

	return 0;
}