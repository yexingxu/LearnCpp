/*
 * @Description:
 * @Version: 2.0
 * @Author: chen, hua
 * @Date: 2022-06-25 12:25:56
 * @LastEditors: chen, hua
 * @LastEditTime: 2022-06-25 12:49:21
 */

#ifndef VECTOR_H_
#define VECTOR_H_

template <class T>
class Vector {
 public:
  Vector() : size_(0), capacity_(0), data_(nullptr) {}
  Vector(int size) : size_(size), capacity_(size), data_(new T[size]) {}
  Vector(int size, T value) : size_(size), capacity_(size), data_(new T[size]) {
    for (int i = 0; i < size; ++i) {
      data_[i] = value;
    }
  }
  Vector(const Vector& other)
      : size_(other.size_),
        capacity_(other.capacity_),
        data_(new T[other.capacity_]) {
    for (int i = 0; i < size_; ++i) {
      data_[i] = other.data_[i];
    }
  }
  Vector& operator=(const Vector& other) {
    if (this != &other) {
      //先释放自己的数据
      if (capacity_) {
        delete[] data_;
      }
      size_ = other.size_;
      capacity_ = other.capacity_;
      data_ = new T[other.capacity_];
      for (int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
      }
    }
    return *this;
  }
  ~Vector() {
    if (capacity_) {
      delete[] data_;
    }
  }
  T& operator[](int index) { return data_[index]; }
  int size() { return size_; }
  int capacity() { return capacity_; }
  void push_back(const T& value) {
    if (size_ == capacity_) {
      capacity_ = capacity_ * 2;
      T* new_data = new T[capacity_];
      for (int i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
      }
      delete[] data_;
      data_ = new_data;
    }
    data_[size_] = value;
    ++size_;
  }
  void pop_back() {
    if (size_ > 0) {
      --size_;
    }
  }
  bool empty() { return size_ == 0; }
  void clear() {
    if (data_) {
      delete[] data_;
    }
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
  }
  void resize(int size) {
    if (size > capacity_) {
      capacity_ = size;
      T* new_data = new T[capacity_];
      for (int i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
      }
      delete[] data_;
      data_ = new_data;
    }
    size_ = size;
  }

 private:
  T* data_;
  int size_;
  int capacity_;
};
#endif  // VECTOR_H_