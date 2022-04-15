#ifndef MAHJONG_H
#define MAHJONG_H
#include "./tool.h"
#include "./User.h"

class CardManage{
public:
    map<string, int> cards;
    vector<string> random_cards;

    CardManage();

    void Random();

    void InitUserCard(User &);

    bool JudgeWin(User);

    string Distribution(User &);

};

#endif
