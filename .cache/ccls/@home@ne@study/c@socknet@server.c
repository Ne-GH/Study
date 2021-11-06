#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <threads.h>

#define SOCKMAX 50
int num = 0;
int cur = 0;
int socks[SOCKMAX];
struct sockaddr clientaddr[SOCKMAX];
socklen_t clientaddrlen = sizeof(struct sockaddr);


int Server(void *pcur){
    printf("线程创建成功\n");
    int cur = *(int *)pcur;
    int sock = socks[cur];
    printf("sock:%d\n",socks[cur]);

    /* char send_buf[255] = {0}; */

    while (1) {
        char read_buf[255] = {0};
        printf("Read开始\n");
        read(sock, read_buf, 255);
        printf("Read结束\n");
        printf("接收到以下信息:%s\n",read_buf);

        /* for(int i = 0;i < SOCKMAX; ++i){ */
            /* if(socks[i] == sock || 0 == socks[i]) */
                /* continue; */

            /* write(socks[i], read_buf, 255); */
        /* } */
    }

    return 0;
}
int main(){

    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in sockadd;
    memset(&sockadd, 0, sizeof(sockadd));
    sockadd.sin_family = PF_INET;
    sockadd.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockadd.sin_port = htons(1234);
    bind(sock, (struct sockaddr*)&sockadd, sizeof(struct sockaddr));
    
    listen(sock, 20);

    while(cur < SOCKMAX){
        socks[num] = accept(sock, &clientaddr[num], &clientaddrlen);
        cur = num++;
        thrd_t thrdsock;
        thrd_create(&thrdsock, &Server, &cur);

    }

    return 0;
}
