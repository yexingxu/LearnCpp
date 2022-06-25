/*
 * @Description:
 * @Version: 2.0
 * @Author: chen, hua
 * @Date: 2022-06-25 11:05:35
 * @LastEditors: chen, hua
 * @LastEditTime: 2022-06-25 11:55:47
 */

#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

template <class T>
class UniquePtr {
 public:
  UniquePtr() : ptr_(nullptr) {}
  UniquePtr(T* ptr) : ptr_(ptr) {}
  UniquePtr(const UniquePtr& other) = delete;
  UniquePtr& operator=(const UniquePtr& other) = delete;
  UniquePtr(const UniquePtr&& other) : ptr_(other.ptr_) {
    other.ptr_ = nullptr;
  }
  UniquePtr& operator=(const UniquePtr&& other) {
    if (this != &other) {
      if (ptr_) {
        delete ptr_;
      }
      ptr_ = other.ptr_;
      other.ptr_ = nullptr;
    }
    return *this;
  }
  ~UniquePtr() {
    if (ptr_) {
      delete ptr_;
    }
  }

  T* operator->() const { return ptr_; }
  T& operator*() const { return *ptr_; }
  T* get() const { return ptr_; }
  T* release() {
    T* tmp = ptr_;
    ptr_ = nullptr;
    return tmp;
  }
  void reset(const T* ptr = nullptr) {
    if (ptr_) {
      delete ptr_;
    }
    ptr_ = ptr;
  }

  explicit operator bool() const { return ptr_ != nullptr; }

 private:
  T* ptr_;
};

#endif  // UNIQUE_PTR_H