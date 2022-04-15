#ifndef USER_H
#define USER_H

#include "./tool.h"


string GetCardType(string,int);
string GetCardType(int , string);


class Card{
public:
    string name;
    int num;
};

class User{
public:
    int id;
    int type;
    string name;
    vector<string> cards;

    User();
    User(int);

    static int GetWeight(string);
    static bool card_sort_cmp(string,string);
    void card_sort();
    string push(int);
    void push(string);
    void ShowCard();

};

#endif
