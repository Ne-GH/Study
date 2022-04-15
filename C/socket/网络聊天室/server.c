#include "./socknet.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int num = 0;
int cur = 0;
int connum = 0;
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
        char buffer[255] = {0};

        Message stackmes;
        read(sock, &stackmes, sizeof(Message));
        Message *mes = malloc(stackmes.len);
        memcpy(mes, &stackmes, sizeof(stackmes));

        read(sock, mes->message, mes->namelen + mes->messagelen + 1);
        /* read(sock, mes->message, mes->namelen + mes->messagelen + 1); */

        // send之前这个也是个NUL,因此这一句可有可无
        mes->message[mes->namelen + mes->messagelen] = NUL;



        // 信息完整接收
        /* printf("len:%d\n",mes->len); */
        /* printf("namelen:%d\n",mes->namelen); */
        /* printf("messagelen:%d\n",mes->messagelen); */
        /* printf("mess:%s\n",mes->message); */
        char name[255] = {0};

        for(int i = 0;i < mes->namelen; ++i){
            name[i] = mes->message[i];
        }
        name[mes->namelen - 1] = NUL;

        // 退出
        if(strcmp(mes->message + mes->namelen, "quit") == 0){

            for(int i = 0;i < SOCKMAX; ++i){
                if(socks[i] <= 0 || socks[i] == sock)
                    continue;
                else{
                    char quit[255] = {0};
                    sprintf(quit, "%s%s%s","用户",name,"退出聊天室");
                    int quitlen = strlen(quit);
                    Message *quitmes = malloc(sizeof(Message) + quitlen + 1);

                    quitmes->len = sizeof(Message) + quitlen + 1;
                    quitmes->namelen = 0;
                    quitmes->messagelen = quitlen;
                    memcpy(quitmes->message, quit, quitlen);

                    printf("%s\n",quitmes->message);
                    quitmes->message[quitlen] = NUL;

                    write(socks[i], quitmes, quitmes->len);

                    free(quitmes);
                }
            }
            sock = 0;
            socks[cur] = 0;
            return 0;
        }

        for(int i = 0;i < SOCKMAX; ++i){
            if(socks[i] <= 0 || socks[i] == sock)
                continue;
            else{
                write(socks[i],mes, mes->len);
            }
        }

        /* for(int i = 0;i < SOCKMAX; ++i){ */
            /* if(socks[i] == sock || 0 == socks[i]) */
                /* continue; */

            /* write(socks[i], read_buf, 255); */
        /* } */
        free(mes);
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
