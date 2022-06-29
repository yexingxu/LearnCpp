/*
 * @Description:
 * @Version: 2.0
 * @Author: chen, hua
 * @Date: 2022-06-25 13:12:31
 * @LastEditors: chen, hua
 * @LastEditTime: 2022-06-25 14:30:04
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdexcept>
template <class T>
class Node {
 public:
  Node(const T& data) : data_(data), next_(nullptr) {}
  T data_;
  Node* next_;
};

template <class T>
class List {
 public:
  List() : head_(nullptr), tail_(nullptr), size_(0) {}
  List(const List& other) : head_(nullptr), tail_(nullptr), size_(0) {
    auto cur = other.head_;
    while (cur) {
      push_back(cur->data_);
      cur = cur->next_;
    }
  }
  List& operator=(const List& other) {
    if (this != &other) {
      //先释放自己的数据
      clear();
      Node<T>* cur = other.head_;
      while (cur) {
        push_back(cur->data_);
        cur = cur->next_;
      }
    }
    return *this;
  }
  ~List() { clear(); }
  void push_back(const T& value) {
    //找到被插入的节点的前驱节点，默认的前驱节点就是头节点
    if (empty()) {
      head_ = tail_ = new Node<T>(value);
    } else {
      tail_->next_ = new Node<T>(value);
      tail_ = tail_->next_;
    }
    ++size_;
  }
  void push_front(const T& value) {
    if (empty()) {
      head_ = tail_ = new Node<T>(value);
    } else {
      head_->next_ = new Node<T>(value);
      head_ = head_->next_;
    }
    ++size_;
  }
  void pop_back() {
    if (empty()) {
      return;
    }
    if (head_ == tail_) {
      delete head_;
      head_ = tail_ = nullptr;
    } else {
      Node<T>* cur = head_;
      while (cur->next_ != tail_) {
        cur = cur->next_;
      }
      delete tail_;
      tail_ = cur;
      tail_->next_ = nullptr;
    }
    --size_;
  }
  void pop_front() {
    if (empty()) {
      return;
    }
    Node<T>* cur = head_;
    head_ = head_->next_;
    delete cur;
    --size_;
  }
  void clear() {
    Node<T>* cur = head_;
    while (cur) {
      Node<T>* tmp = cur;
      cur = cur->next_;
      delete tmp;
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;  //清空后size_为0
  }

  void reserve() noexcept {
    if (empty()) {
      return;
    }
    Node<T>* cur = head_;
    Node<T>* pre = nullptr;
    while (cur) {
      Node<T>* tmp = cur->next_;
      cur->next_ = pre;
      pre = cur;
      cur = tmp;
    }
    head_ = pre;
  }
  bool empty() const { return size_ == 0; }
  bool exist(const T& value) const {
    Node<T>* cur = head_;
    while (cur) {
      if (cur->data_ == value) {
        return true;
      }
      cur = cur->next_;
    }
    return false;
  }
  T& front() {
    if (empty()) {
      throw std::runtime_error("list is empty");
    }
    return head_->data_;
  }
  const T& front() const {
    if (empty()) {
      throw std::runtime_error("list is empty");
    }
    return head_->data_;
  }
  T& back() {
    if (empty()) {
      throw std::runtime_error("list is empty");
    }
    return tail_->data_;
  }
  const T& back() const {
    if (empty()) {
      throw std::runtime_error("list is empty");
    }
    return tail_->data_;
  }

  int size() const { return size_; }
  T& operator[](int index) {
    if (index < 0 || index >= size_) {
      throw std::out_of_range("index out of range");
    }
    Node<T>* cur = head_;
    for (int i = 0; i < index; ++i) {
      cur = cur->next_;
    }
    return cur->data_;
  }

 private:
  Node<T>* head_;
  Node<T>* tail_;
  int size_;
};

#endif  // LIST_H_