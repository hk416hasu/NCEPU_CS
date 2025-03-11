#include <iostream>
using namespace std;


auto main() -> int {
  int a1{}; // 空初始化列表, 默认为0
  int a2{0}; // 初始化列表直接初始化为0
  int a3 = {0}; // 拷贝初始化列表为0
  int a4(); // 这是tm声明了个函数, 参数为空, 返回值为int
  int a5(0); // 直接初始化为0
  int a6 = 0; // 拷贝初始化为0
  int a7 = (0); // 比a6多加了对括号而已
  int a8(void); // 同a4
              // 另外，对于int这种Plain Old Data, 没有什么拷贝赋值, 符合语法,
              // 编译器直接赋值就行, 只是为了方便理解

  cout << a1 << endl;
  cout << a2 << endl;
  cout << a3 << endl;
  cout << a4 << endl; // 对于函数指针, cout没有对应重载来直接输出, 会转bool型
  cout << a5 << endl;
  cout << a6 << endl;
  cout << a7 << endl;
  cout << a8 << endl;

  return 0;
}
