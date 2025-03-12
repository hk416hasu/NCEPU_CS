#include "my_unique_ptr.h"
#include <iostream>
#include <utility>

int main() {

  my_unique_ptr<int> up(new int(5));
  std::cout << "*up  = " << *up << '\n';

  // my_unique_ptr<int> up2(up); // 测试拷贝构造
  // my_unique_ptr<int> up3; // 测试拷贝赋值
  // up3 = up;

  // 测试移动构造 
  my_unique_ptr<int> up4(std::move(up));
  std::cout << "*up4 = " << *up4 << '\n';
  std::cout << "up   = " << (void*)(up.get()) << '\n';

  // 测试移动赋值
  my_unique_ptr<int> up5;
  up5 = std::move(up4);
  std::cout << "*up5 = " << *up5 << '\n';
  std::cout << "up4  = " << (void*)(up4.get()) << '\n';


  return 0;
}
