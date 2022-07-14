/*
 * @Author: yexingxu
 * @Date: 2022-07-14 10:59:08
 * @LastEditors: yexingxu
 * @LastEditTime: 2022-07-14 11:37:57
 * @Description: 请填写简介
 */
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MCAST_PORT 8888
#define LOCAL_ADDR "127.0.0.1" /*本机网卡地址*/

#define ERR_EXIT(m)     \
  do {                  \
    perror(m);          \
    exit(EXIT_FAILURE); \
  } while (0)

void echo_ser(int sock) {
  char recvbuf[1024] = {0};
  struct sockaddr_in peeraddr;
  socklen_t peerlen;
  int i = 0;

  while (1) {
    peerlen = sizeof(peeraddr);
    memset(recvbuf, 0, sizeof(recvbuf));
    int n = recvfrom(sock, recvbuf, sizeof(recvbuf), 0,
                     (struct sockaddr *)&peeraddr, &peerlen);
    if (n == -1) {
      if (errno == EINTR) continue;

      ERR_EXIT("recvfrom error");
    } else if (n > 0) {
      printf("==>(%d)-%s\n", ++i, recvbuf);
    }
  }
  close(sock);
}

int main(void) {
  int sock;
  if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0) ERR_EXIT("socket error");

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(MCAST_PORT);
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  int yes = 1;
  if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
    perror("Reusing ADDR failed");
    exit(1);
  }

  if (bind(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    ERR_EXIT("bind error");

  echo_ser(sock);

  return 0;
}