#ifndef INFO_H
#define INFO_H

#include "tool.h"

class Info{
    string _webname;
    string _account;
    string _password;
    string _email;

public:
    Info(){  }
    Info(string web,string account,string password){ 
        _webname = web;
        _account = account;
        _password = password;
    }
    Info(string web,string account,string password,string email){ 
        _webname = web;
        _account = account;
        _password = password;
        _email = email;
    }


    void SetWebName(string web){
        _webname = web;
    }
    void SetAccount(string account){
        _account = account;
    }
    void SetPassword(string password){
        _password = password;
    }
    void SetEmail(string email){
        _email = email;
    }


    string GetWebName(){
        return _webname;
    }
    string GetAccount(){
        return _account;
    }
    string GetPassWord(){
        return _password;
    }
    string GetEmail(){
        return _email;
    }
    

    friend istream &operator >>(istream &in,Info &info){
        string web_name,account,password,email;
        in >> web_name >> account >> password >> email;
        return in;
    }

    friend ostream &operator <<(ostream &out,Info info){
        out << "WebName:" << info.GetWebName() << endl
            << "Account:" << info.GetAccount() << endl
            << "PassWord:" << info.GetPassWord() << endl
            << "Email:" << info.GetEmail() << endl;
        return out;
    }


};


#endif
