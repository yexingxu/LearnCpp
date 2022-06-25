/*
 * @Description:
 * @Version: 2.0
 * @Author: chen, hua
 * @Date: 2022-06-25 11:56:07
 * @LastEditors: chen, hua
 * @LastEditTime: 2022-06-25 12:16:11
 */

#ifndef SHARED_PTR_H_
#define SHARED_PTR_H_

#include <memory>
template <class T>
class SharedPtr {
 public:
  SharedPtr() {}
  SharedPtr(T* ptr) : ptr_(ptr), ref_count_(new int(1)) {}
  SharedPtr(const SharedPtr& other) {
    if (other.ptr_) {
      ptr_ = other.ptr_;
      ref_count_ = other.ref_count_;
      ++(*ref_count_);
    }
  }
  SharedPtr& operator=(const SharedPtr& other) {
    if (this != &other) {
      if (ref_count_) {
        --(*ref_count_);
        if (*ref_count_ == 0) {
          delete ref_count_;
          delete ptr_;
        }
      }
      ptr_ = other.ptr_;
      ref_count_ = other.ref_count_;
      if (ref_count_) {
        ++(*ref_count_);
      }
    }
    return *this;
  }
  ~SharedPtr() {
    if (ref_count_) {
      --(*ref_count_);
      if (*ref_count_ == 0) {
        delete ref_count_;
        delete ptr_;
      }
    }
  }
  T* operator->() { return ptr_; }
  T& operator*() { return *ptr_; }
  bool expired() { return !ref_count_ || *ref_count_ == 0; }
  int use_count() { return ref_count_ ? *ref_count_ : 0; }
  T* get() { return ptr_; }
  T* lock() {
    if (ref_count_) {
      ++(*ref_count_);
    }
    return ptr_;
  }
  void reset(const T* ptr = nullptr) {
    if (ptr_) {
      delete ptr_;
    }
    ptr_ = ptr;
  }
  explicit operator bool() const { return ptr_ != nullptr; }
  void swap(SharedPtr& other) { std::swap(ptr_, other.ptr_); }

 private:
  T* ptr_;
  int* ref_count_;
};

#endif  // SHARED_PTR_H_
