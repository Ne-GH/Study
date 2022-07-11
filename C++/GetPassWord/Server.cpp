#include "tool.h"
#include "Info.h"
#include "InfoManager.h"


int main(){

    InfoManager im("./test.database");

    string webname,account,password,email;
    cout << "webname:";
    cin >> webname;
    cout << "account:";
    cin >> account;
    cout << "password:";
    cin >> password;
    cout << "email:";
    cin >> email;

    Info info(webname,account,password,email);
    im.AddInfo(info);

    im.ShowInfo();



    return 0;
}
