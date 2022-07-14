/*
 * @Author: yexingxu
 * @Date: 2022-07-14 11:00:07
 * @LastEditors: yexingxu
 * @LastEditTime: 2022-07-14 11:50:40
 * @Description: 请填写简介
 */
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MCAST_PORT 8888
#define LOCAL_ADDR "127.0.0.1"   /*本机网卡地址*/
#define UDP_DATA "UDP TEST DATA" /*UDP发送的数据*/
#define UDP_INTERVAL 1           /*发送间隔时间*/

#define ERR_EXIT(m)     \
  do {                  \
    perror(m);          \
    exit(EXIT_FAILURE); \
  } while (0)

void echo_cli(int sock) {
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(MCAST_PORT);
  servaddr.sin_addr.s_addr = inet_addr(LOCAL_ADDR);

  while (1) {
    int ret = sendto(sock, UDP_DATA, strlen(UDP_DATA), 0,
                     (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret < 0) {
      perror("sendto()");
      exit(1);
    }
    sleep(UDP_INTERVAL); /*等待一段时间*/
  }

  close(sock);
}

int main(void) {
  int sock;
  if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0) ERR_EXIT("socket");

  echo_cli(sock);

  return 0;
}