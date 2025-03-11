#include <iostream>
#include <utility>

void func(int& x) { std::cout << "左值引用" << std::endl; }
void func(int&& x) { std::cout << "右值引用" << std::endl; }

int main() {
    int a = 10;
    func(std::move(a)); // 输出：右值引用
    func(a);          // 输出：左值引用
    // std::move()后，a并没有被销毁, 说明move()并不会“将左值改变为右值”
    // 只是“强制视为右值”
    // 其实现可以用 T&&, 注意仅在模板类型下是通用引用(同时匹配左值引用 与右值引用)
    return 0;
}

