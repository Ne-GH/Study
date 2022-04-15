#include "./MahJong.h"



int main(){

    CardManage CM;


    User user1,user2,user3,user4(1);
    CM.InitUserCard(user1);
    CM.InitUserCard(user2);
    CM.InitUserCard(user3);
    CM.InitUserCard(user4);

    user1.cards[0] = "五万";
    user1.cards[1] = "六万";
    user1.cards[2] = "七万";
    user1.cards[3] = "八条";
    user1.cards[4] = "八条";
    user1.cards[5] = "八条";
    user1.cards[6] = "一筒";
    user1.cards[7] = "一筒";
    user1.cards[8] = "二筒";
    user1.cards[9] = "三筒";
    user1.cards[10] = "四筒";
    user1.cards[11] = "四筒";
    user1.cards[12] = "五筒";
    CM.random_cards.push_back("六筒");
    CM.Distribution(user1) ;
#ifdef DEBUG
    cout << CM.JudgeWin(user1) << endl;
#endif

    // while(CM.random_cards.size() != 0){
//
//
        // cout << endl << "You get card:" << CM.distribution(user1) << endl;
        // user1.card_sort();
        // user1.ShowCard();
        // CM.JudgeWin(user1);
//
        // int pos = 0;
        // cin >> pos;
        // user1.push(pos);
    // }
        // CM.distribution(user2);
        // cout << "user2 push " << user2.push(0) << endl;
        // CM.distribution(user3);
        // cout << "user3 push " << user3.push(0) << endl;
        // CM.distribution(user4);
        // cout << "user4 push " << user4.push(0) << endl;

        // cout << "user1 get :" << CM.distribution(user1) << endl;
        // cout << "user1 push :" << user1.push(0) << endl << endl;

        // cout << "user2 get :" << CM.distribution(user2) << endl;
        // cout << "user2 push :" << user2.push(0) << endl << endl;

        // cout << "user3 get :" << CM.distribution(user3) << endl;
        // cout << "user3 push :" << user3.push(0) << endl << endl;

        // cout << "user4 get :" << CM.distribution(user4) << endl;
        // cout << "user4 push :" << user4.push(0) << endl << endl;


    // }

    // user1.card_sort();
    // cout << "User1" << endl;
    // for(auto _ : user1.cards){
        // cout << _ << endl;
       // cout << CM.cards_map[_] << endl;
    // }
    // cout << endl << endl;
//
    // user2.card_sort();
    // cout << "User2" << endl;
    // for(auto _ : user2.cards){
        // cout << _ << endl;
       // cout << CM.cards_map[_] << endl;
    // }
    // cout << endl << endl;
//
    // user3.card_sort();
    // cout << "User3" << endl;
    // for(auto _ : user3.cards){
        // cout << _ << endl;
       // cout << CM.cards_map[_] << endl;
    // }
    // cout << endl << endl;
//
    // user4.card_sort();
    // cout << "User4" << endl;
    // for(auto _ : user4.cards){
        // cout << _ << endl;
       // cout << CM.cards_map[_] << endl;
    // }
    // cout << endl << endl;



    return 0;
}

