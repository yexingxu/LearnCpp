/*
 * @Author: yexingxu
 * @Date: 2022-07-12 19:27:10
 * @LastEditors: yexingxu
 * @LastEditTime: 2022-07-12 19:31:17
 * @Description: 请填写简介
 */
#include <iostream>
#include <thread>

using namespace std;

int main() {
  thread t([] { cout << "Hello World from lambda thread." << endl; });

  t.join();

  return 0;
}