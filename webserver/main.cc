/*
 * @Author: yexingxu
 * @Date: 2022-07-08 19:46:07
 * @LastEditors: yexingxu
 * @LastEditTime: 2022-07-12 18:08:58
 * @Description: 请填写简介
 */

#include <arpa/inet.h>
#include <assert.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <ctime>
#include <iomanip>
#include <mutex>
#include <thread>

#include "byteorder.h"

using namespace std;
static bool stop = false;
static void handle_term(int sig) { stop = true; }

// reinterpret_cast运算符是用来处理无关类型之间的转换；它会产生一个新的值，这个值会有与原始参数（expressoin）有完全相同的比特位。
void test_reinterpret_cast() {
  int num = 0x00636261;  //用16进制表示32位int，0x61是字符'a'的ASCII码
  int* pnum = &num;
  char* pstr = reinterpret_cast<char*>(pnum);
  cout << "pnum指针的值: " << pnum << endl;
  cout
      << "pstr指针的值: " << static_cast<void*>(pstr)
      << endl;  //直接输出pstr会输出其指向的字符串，这里的类型转换是为了保证输出pstr的值
  cout << "pnum指向的内容: " << hex << *pnum << endl;
  cout << "pstr指向的内容: " << pstr << endl;
}

void testlisten(int argc, char* argv[]) {
  signal(SIGTERM, handle_term);

  if (argc <= 3) {
    printf("usage: %s ip_address port_number backlog\n", basename(argv[0]));
  }
  const char* ip = argv[1];
  int port = atoi(argv[2]);
  int backlog = atoi(argv[3]);

  int sock = socket(PF_INET, SOCK_STREAM, 0);
  assert(sock >= 0);

  struct sockaddr_in address;
  bzero(&address, sizeof(address));
  address.sin_family = AF_INET;
  inet_pton(AF_INET, ip, &address.sin_addr);
  address.sin_port = htons(port);
  int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
  assert(ret != -1);

  ret = listen(sock, backlog);
  assert(ret != -1);

  while (!stop) {
    sleep(1);
  }

  close(sock);
}

int main(int argc, char* argv[]) {
  test_reinterpret_cast();
  testlisten(argc, argv);
  ByteOrder();
  std::once_flag flag;
  // std::put_time(std::localtime(std::get_time(std::tm *__tmb, const _CharT
  // *__fmt)));
  return 0;
}
