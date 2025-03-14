template <typename T>
class my_unique_ptr {
private:
  T *m_ptr;
public:
  explicit my_unique_ptr(T *ptr = nullptr) noexcept : m_ptr(ptr) {}
  ~my_unique_ptr() {
    delete this->m_ptr;
  }

  my_unique_ptr(const my_unique_ptr &) = delete;
  my_unique_ptr(my_unique_ptr &&other) {
    this->m_ptr = other.m_ptr;
    other.m_ptr = nullptr;
  }

  my_unique_ptr & operator=(const my_unique_ptr &) = delete;
  my_unique_ptr & operator=(my_unique_ptr &&other) {
    if (this == &other) {
      return *this;
    }
    delete m_ptr;
    this->m_ptr = other.m_ptr;
    other.m_ptr = nullptr;
    return *this;
  }

  T& operator*() const noexcept {
    return *m_ptr;
  }

  T* operator->() const noexcept {
    return m_ptr;
  }

  void reset (T *ptr = nullptr) {
    delete m_ptr;
    m_ptr = ptr;
  }

  T* release() {
    T *tmp = m_ptr;
    m_ptr = nullptr;
    return tmp;
  }

  T* get() const noexcept {
    return m_ptr;
  }

};
