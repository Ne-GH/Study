#include "./socknet.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int sock = 0;
int namelen = 0;
char name[255] = {0};

int Client(void *arg){

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
        printf("%s\n",mes->message);

    }
    return 0;

}
int main(){

    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family = PF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1234);
    connect(sock, (struct sockaddr*)&addr, sizeof(addr));

    // 创建一个线程用来监听server的信息
    thrd_t client_thrd;
    thrd_create(&client_thrd, &Client,NULL);

    
    printf("请输入用户名:");
    scanf("%[^\n]%*c",name);
    namelen = strlen(name);
    name[namelen] = ':';
    namelen = strlen(name);



    while(1){

        char buffer[255] = {0};
        // 处理输入的信息
        scanf("%[^\n]%*c",buffer);
        int messagelen = strlen(buffer);

        int alllen = sizeof(Message) + namelen + messagelen + 1;
        
        Message *mes = malloc(alllen);
        mes->len = alllen;
        mes->namelen = namelen;
        mes->messagelen = messagelen;
        memcpy(mes->message, name, namelen);
        memcpy(mes->message + namelen, buffer, mes->messagelen);

        mes->message[namelen + messagelen] = NUL;

        /* printf("len:%d\n",mes->len); */
        /* printf("namelen:%d\n",mes->namelen); */
        /* printf("Message:%s\n",mes->message); */
        /* for(int i = 0;i < mes->messagelen; ++i){ */
            /* printf("%d:%c\t",mes->message[i],mes->message[i]); */
        /* } */
        /* putchar(10); */
        
        write(sock, mes, mes->len);
        free(mes);

        if(strcmp(buffer, "quit") == 0){
            sock = 0;
            close(sock);
            printf("程序正常退出\n");
            exit(0);
        }


        
    
    }




    return 0;
}
