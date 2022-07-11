#ifndef SOCKET_H
#define SOCKET_H

#include "tool.h"
#include "Info.h"

class Socket{
    int _sock;
    struct sockaddr_in _sockadd;
    string _ip;
public:
    Socket(string ip){
        _ip = ip;
        _sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        memset(&_sockadd, 0,sizeof(_sockadd));
        _sockadd.sin_family = PF_INET;
        _sockadd.sin_addr.s_addr = inet_addr(ip.c_str());
        _sockadd.sin_port = htons(PORT);
    }

    void IsClient(){
        connect(_sock,(struct sockaddr *)&_sockadd,sizeof(_sockadd));

    }
    void IsServer(){
        bind(_sock,(struct sockaddr *)&_sockadd,sizeof(struct sockaddr));
        listen(_sock, 20);

    }

    Info Read(Info info){
        char info_buff[1024] = {0};
        read(_sock,&info_buff,sizeof(info_buff));
        string info_string(info_buff);

    }

    void Write(){

    }
};

#endif
