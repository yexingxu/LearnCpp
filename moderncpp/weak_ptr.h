/*
 * @Description: weak_ptr：解决循环引用的问题
 * @Version: 2.0
 * @Author: chen, hua
 * @Date: 2022-06-25 11:20:40
 * @LastEditors: chen, hua
 * @LastEditTime: 2022-06-25 11:38:09
 */
#ifndef WEAK_PTR_H
#define WEAK_PTR_H

template <class T>
class WeakPtr {
 public:
  WeakPtr() : ptr_(nullptr), ref_count_(nullptr) {}
  WeakPtr(T* ptr) : ptr_(ptr), ref_count_(new int(1)) {}
  WeakPtr(const WeakPtr& other)
      : ptr_(other.ptr_), ref_count_(other.ref_count_) {
    if (ref_count_) {
      ++(*ref_count_);
    }
  }
  WeakPtr& operator=(const WeakPtr& other) {
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
  ~WeakPtr() {
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

 private:
  T* ptr_;
  int* ref_count_;
};
#endif  // WEAK_PTR_H