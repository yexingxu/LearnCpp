/*
 * @Author: yexingxu
 * @Date: 2022-07-12 19:33:53
 * @LastEditors: yexingxu
 * @LastEditTime: 2022-07-12 19:48:13
 * @Description: 请填写简介
 */
#include <chrono>
#include <cmath>
#include <functional>

class Future {
 public:
  Future() : value_(0) {}
  Future(double value) : value_(value) {}
  double get() const { return value_; }
  void set(double value) { value_ = value; }
  Future& then(std::function<double(double)> f) {
    value_ = f(value_);
    return *this;
  }

 private:
  double value_;
};
