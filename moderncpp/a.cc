/*
 * @Description:
 * @Version: 2.0
 * @Author: chen, hua
 * @Date: 2022-04-08 23:01:00
 * @LastEditors: chen, hua
 * @LastEditTime: 2022-06-25 13:47:40
 */
// bubbling sort
#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

#include "list.h"
#include "shared_ptr.h"
using namespace std;

int main() {
  std::shared_ptr<int> i_ptr(new int(1));
  std::vector<int> va;
  std::list<int> la;
  la.reverse();
  SharedPtr<int> sp(new int(1));
  List<int> lla;
}
