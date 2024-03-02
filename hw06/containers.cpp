#include <cstddef>

template <typename T> class IContainer {
public:
  virtual ~IContainer() {}

  virtual void push_back(T value) = 0;
  virtual void insert(T value, size_t index) = 0;
  virtual void erase() = 0;
  virtual void erase(size_t index) = 0;
  virtual size_t size() const = 0;
};

template <typename T> class Vec : public IContainer<T> {
public:
  Vec() { _data = new T[0]; }
  Vec(size_t cap) {
    _cap = cap;
    _data = new T[cap];
  }
  void push_back(T value) override {
    if (_len == _cap) {
      enlarge_to((_cap == 0) ? 1 : _cap * 2);
    }
    _data[_len++] = value;
  }
  void insert(T value, size_t index) override {}
  void erase() override {}
  void erase(size_t index) override {}
  size_t size() const override { return _len; }

private:
  void enlarge_to(size_t new_cap) {
    T *new_data = new T[new_cap];
    for (size_t i = 0; i < _cap; ++i) {
      new_data[i] = _data[i];
    }
    _cap = new_cap;
    delete[] _data;
    _data = new_data;
  }

  size_t _len;
  size_t _cap;
  T _data[];
};

int main() {}
