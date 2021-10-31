#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <threads.h>

#define NUL      '\0'
#define SOCKMAX  50

typedef struct Message{
    int len;
    int namelen;
    int messagelen;

    // message的长度分为namelen + messagelen
    char message[0];
}Message;
