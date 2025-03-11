#include <iostream>

// 返回类型后置
auto add(int a, int b) -> double {
   return a + b;
}

auto main() -> int {
   std::cout << add(2, 3) << '\n';
   return 0;
}
