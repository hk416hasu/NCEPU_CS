#include <iostream>
#include <functional>

// 匿名函数语法糖lambda:
//    [capture](parameter_list) -> return_type { function_body };

// segmentation fault, 试图访问已经释放的栈上元素
std::function<int()> func() {
   int count = 0;
   return [&count]() -> int { return ++count; };
}

std::function<int()> func() {
    int count = 0;
    return [count]() mutable { return ++count; };
}

int main() {
   std::function<int()> counter1 = func();
   std::function<int()> counter2 = func();

   std::cout << counter1() << '\n';
   std::cout << counter1() << '\n';
   std::cout << counter1() << '\n';
   
   std::cout << counter2() << '\n';
   std::cout << counter2() << '\n';
   std::cout << counter2() << '\n';

   return 0;
}
