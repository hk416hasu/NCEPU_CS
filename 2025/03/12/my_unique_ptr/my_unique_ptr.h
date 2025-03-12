#ifndef MY_UNIQUE_PTR_H
#define MY_UNIQUE_PTR_H

#include <algorithm>

// 1. 利用 C++11 的特性，编写一个 unique_ptr 的库，实现类似 std::unique_ptr 的功能。
// 实现核心的内存管理功能即可，其他功能例如 deleter 相关、操作符的支持等可以不实现。

template<typename T>
class my_unique_ptr {
private:
  T *m_ptr;
public:
  explicit my_unique_ptr(T *ptr = nullptr) noexcept : m_ptr(ptr) {}
  ~my_unique_ptr() {
    delete this->m_ptr;
    this->m_ptr = nullptr;
  }

  // 资源独占, 故禁用拷贝构造函数与拷贝赋值函数
  my_unique_ptr(const my_unique_ptr &) = delete;
  auto operator=(const my_unique_ptr &) -> my_unique_ptr & = delete;

  // 移动构造函数
  my_unique_ptr(my_unique_ptr &&other) noexcept : m_ptr(other.m_ptr) {
    other.m_ptr = nullptr;
  }
  // 移动赋值函数
  auto operator=(my_unique_ptr &&other) -> my_unique_ptr & {
    if (this == &other) { return *this; } // 防止自赋值

    delete this->m_ptr; // 释放当前资源
    this->m_ptr = other.m_ptr; // 转移资源
    other.m_ptr = nullptr;
    return *this;
  }

  // 替换管理资源
  void reset(T *ptr = nullptr) noexcept {
    delete m_ptr;
    m_ptr = ptr;
  }

  // 释放所有权，返回指针，但不 delete
  T* release() noexcept {
    T *tmp = this->m_ptr;
    this->m_ptr = nullptr;
    return tmp;
  }

  // 交换管理对象
  void swap(my_unique_ptr &other ) noexcept {
    std::swap(this->m_ptr, other.m_ptr);
  }

  // 返回指向管理对象的指针
  T* get() const noexcept {
    return m_ptr;
  }

  // 检查是否有关联的管理对象, 即是否有 get() != nullptr
  explicit operator bool() const noexcept {
    return this->m_ptr != nullptr;
  }

  // 重载 * 和 -> 以模拟指针操作
  T &operator*() const noexcept { return *m_ptr; }
  T *operator->() const noexcept { return m_ptr; }

};

#endif
