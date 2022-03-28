#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

namespace mystl {

template <typename _Tp, typename _Alloc>
class vector {
 public:
  vector();

 private:
  _Tp *start_;
  _Tp *finish_;
  _Tp *end_;
};

}  // namespace mystl

#endif  // MY_VECTOR_H_