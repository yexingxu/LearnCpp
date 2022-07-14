/*
 * @Author: yexingxu
 * @Date: 2022-07-08 19:20:58
 * @LastEditors: yexingxu
 * @LastEditTime: 2022-07-08 19:45:00
 * @Description: 请填写简介
 */

#ifndef BYTE_ORDER_H_
#define BYTE_ORDER_H_

#include <iostream>

inline void ByteOrder() {
  union {
    short value;
    char union_bytes[sizeof(short)];
  } test;
  test.value = 0x0102;
  if ((test.union_bytes[0] == 1) && (test.union_bytes[1] == 2)) {
    printf("big endian\n");
  } else if ((test.union_bytes[0] == 2) && (test.union_bytes[1] == 1)) {
    printf("little endian\n");
  } else {
    printf("unknown...\n");
  }
}
#endif