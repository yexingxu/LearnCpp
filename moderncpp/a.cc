/*
 * @Description:
 * @Version: 2.0
 * @Author: chen, hua
 * @Date: 2022-04-08 23:01:00
 * @LastEditors: chen, hua
 * @LastEditTime: 2022-06-25 14:14:46
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
  for (int i = 0; i < 10; i++) {
    lla.push_back(i);
    std::cout << lla[i] << " ";
  }
  std::cout << std::endl;
  lla.reserve();
  for (int i = 0; i < lla.size(); i++) {
    std::cout << lla[i] << " ";
  }
}
