#include <cstdio>

struct Myclass {
   int m_a;
   int m_b;
   Myclass() {
      printf("call constructor\n");
   }
   Myclass(int a, int b) : m_a(a), m_b(b) {}
   ~Myclass() {
      printf("call destructor\n");
   }
   Myclass(const Myclass &foo) {
      printf("call copy\n");
   }
   void bar() {
      Myclass(); // 错误地希望显示调用构造函数
         // 但只是创建了匿名对象
   }
};

int main() {
   Myclass foo{Myclass()};
   Myclass bar{foo};
   Myclass bar{2, 3};
   // foo.bar();
   return 0;
}
