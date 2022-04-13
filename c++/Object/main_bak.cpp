#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <map>
using namespace std;

#define DEBUG

string GetCardType(string card_type,int num){
    return card_type + to_string(num);
}

string GetCardType(int num,string card_type){
    string str_num;
    switch (num) {
        case 1:
            str_num = "一";
            break;
        case 2:
            str_num = "二";
            break;
        case 3:
            str_num = "三";
            break;
        case 4:
            str_num = "四";
            break;
        case 5:
            str_num = "五";
            break;
        case 6:
            str_num = "六";
            break;
        case 7:
            str_num = "七";
            break;
        case 8:
            str_num = "八";
            break;
        case 9:
            str_num = "九";
            break;
        default:
            break;
    }
    return str_num + card_type;
}

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


    User(){
        id = 0;
        type = 0;
        name = "user1";
    }

    User(int type){
        id = 0;
        this->type = type;
    }

    static int GetWeight(string str){
        int weight = 0;
        if(str.size() <= 4){
            if(str == "东")
                weight = 40;
            else if(str == "南")
                weight = 50;
            else if(str == "西")
                weight = 60;
            else if(str == "北")
                weight = 70;
            else if(str == "中")
                weight = 80;
            else if(str == "發")
                weight = 90;
            else if(str == "白")
                weight = 100;
            else
                ;
        }
        else{
            string str_front(str.begin(),str.begin()+str.size()/2);
            string str_back(str.begin()+str.size()/2,str.end());
            if(str_front == "一")
                weight += 1;
            else if(str_front == "二")
                weight += 2;
            else if(str_front == "三")
                weight += 3;
            else if(str_front == "四")
                weight += 4;
            else if(str_front == "五")
                weight += 5;
            else if(str_front == "六")
                weight += 6;
            else if(str_front == "七")
                weight += 7;
            else if(str_front == "八")
                weight += 8;
            else if(str_front == "九")
                weight += 9;
            else
                ;


            if(str_back == "万")
                weight += 0;
            else if(str_back == "条")
                weight += 10;
            else if(str_back == "筒")
                weight += 20;
            else
                ;

        }
        return weight;
    }

    static bool card_sort_cmp(string str1,string str2){
        return GetWeight(str1) < GetWeight(str2);
    }

    void card_sort(){
        sort(this->cards.begin(),this->cards.end(),card_sort_cmp);
    }

    string push(int pos){

        if(pos < 0 || pos >= this->cards.size()){
            cout << "pos is error !!!" << endl;
        }
        string ret_card = *(this->cards.begin()+pos);
        this->cards.erase(this->cards.begin()+pos);

        return ret_card;
    }

    void push(string cardname){
        auto pos = find(this->cards.begin(),this->cards.end(),cardname);
        if(pos == this->cards.end()){
            cout << "this card not found" << endl;
        }
        this->cards.erase(pos);
    }

    void ShowCard(){
        for(int i = 0;i < this->cards.size(); ++i){
            printf("%-5d",i);
        }
        cout << endl;
        for(auto _ : this->cards){
            printf("%-7s",_.c_str());
            // cout << _ << " ";
        }
        cout << endl;
    }

};

class CardManage{
public:
    map<string,int> cards;
    // map<string,string> cards_map;

    vector<string> random_cards;

    CardManage(){

        // 筒
        for(int i = 1;i <= 9 ; ++i){
            cards.insert({GetCardType(i,"筒"),4});
            // cards.insert({GetCardType("Tong", i),4});
            // cards_map.insert({GetCardType("Tong", i),GetCardType(i,"筒")});
        }
        // 万
        for(int i = 1;i <= 9; ++i){
            cards.insert({GetCardType(i,"万"),4});
            // cards.insert({GetCardType("Wan", i),4});
            // cards_map.insert({GetCardType("Wan", i),GetCardType(i,"万")});
        }
        // Tiao
        for(int i = 1;i <= 9; ++i){
            cards.insert({GetCardType(i,"条"),4});
            // cards.insert({GetCardType("Tiao", i),4});
            // cards_map.insert({GetCardType("Tiao", i),GetCardType(i,"条")});
        }
        
        // 东 南 西 北 中 发 白
        cards.insert({"东",4});
        // cards.insert({"Dong",4});
        // cards_map.insert({"Dong","东"});
        cards.insert({"南",4});
        // cards.insert({"Nan",4});
        // cards_map.insert({"Nan","南"});
        cards.insert({"西",4});
        // cards.insert({"Xi",4});
        // cards_map.insert({"Xi","西"});
        cards.insert({"北",4});
        // cards.insert({"Bei",4});
        // cards_map.insert({"Bei","北"});
        cards.insert({"中",4});
        // cards.insert({"Zhong",4});
        // cards_map.insert({"Zhong","中"});
        cards.insert({"發",4});
        // cards.insert({"Fa",4});
        // cards_map.insert({"Fa","發"});
        cards.insert({"白",4});
        // cards.insert({"Bai",4});
        // cards_map.insert({"Bai","白"});
        


        Random();
        

    }

    void Random(){
        // Get cource cards
        for(auto _ : this->cards){
            random_cards.push_back(_.first);
            random_cards.push_back(_.first);
            random_cards.push_back(_.first);
            random_cards.push_back(_.first);
        }

        default_random_engine re;
        uniform_int_distribution<int> random_engine(0,this->random_cards.size()-1);
        for(int i = 0;i < 10000; ++i){
            int swap1 = random_engine(re);
            int swap2 = random_engine(re);

            string swap_temp = this->random_cards[swap1];
            this->random_cards[swap1] = this->random_cards[swap2];
            this->random_cards[swap2] = swap_temp;

        }

    }

    void InitUserCard(User &user){
        int num = 13;
        if(user.type == 1)
            num ++;

        for(int i = 0;i < num; ++i){
            user.cards.push_back(this->random_cards.back());
            this->cards[this->random_cards.back()] --;
            this->random_cards.pop_back();
        }
    }


    bool JudgeWin(User user1){
        
        #ifdef DEBUG
        user1.ShowCard();
        #endif


        vector<int>nums(user1.cards.size());
        map<int,int>nums_map;

        for(int i = 0;i < user1.cards.size(); ++i){
            nums[i] = User::GetWeight(user1.cards[i]);
            nums_map[nums[i]] ++;
        }


        int same = 0;
        int in_a_row = 0;
        for(int i = 0;i <= nums.size()-3;){

            if((nums[i] == nums[i+1]) && (nums[i+1] == nums[i+2])){
#ifdef DEBUG
                cout << "same: " << i << endl;
#endif
                same ++;
                nums_map[nums[i]] -= 3;
                i += 3;
            }

            else if((nums[i]+1 == nums[i+1]) && (nums[i+1]+1 == nums[i+2])){
                nums_map[nums[i]]--;
                nums_map[nums[i+1]]--;
                nums_map[nums[i+2]]--;

#ifdef DEBUG
                cout << "in_a_row : " << i << endl;
#endif
                in_a_row ++;
                i += 3;
            }
            else
                i += nums_map[nums[i]];

        }

#ifdef DEBUG
        cout << "same: " << same << endl << "in_a_row: " << in_a_row << endl;
#endif
        int couple = 0;
        for(auto _ : nums_map){
            if(_.second >= 2){
                couple ++;
                break;
            }
        }

        if((same + in_a_row == 4) && couple == 1)
            return true;
        

        return false;
    }

    string distribution(User &user){
        if(this->random_cards.size() == 0){
            cout << "haven't Card";
            return "";
        }

        string ret_card = this->random_cards.back();

        user.cards.push_back(this->random_cards.back());
        this->cards[this->random_cards.back()] --;
        this->random_cards.pop_back();

        if(JudgeWin(user) == true){
            cout << user.name << "is winer !!!" << endl;
            exit(0);
        }

        return ret_card;
    }
};


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
    CM.distribution(user1) ;
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

