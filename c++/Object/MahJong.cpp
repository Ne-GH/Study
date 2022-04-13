#include "./MahJong.h"
#include "User.h"

#define DEBUG




CardManage::CardManage(){

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

void CardManage::Random(){
    // Get cource cards
    for(auto _ : this->cards){
        random_cards.push_back(_.first);
        random_cards.push_back(_.first);
        random_cards.push_back(_.first);
        random_cards.push_back(_.first);
    }

    std::default_random_engine re;
    std::uniform_int_distribution<int> random_engine(0,this->random_cards.size()-1);
    for(int i = 0;i < 10000; ++i){
        int swap1 = random_engine(re);
        int swap2 = random_engine(re);

        string swap_temp = this->random_cards[swap1];
        this->random_cards[swap1] = this->random_cards[swap2];
        this->random_cards[swap2] = swap_temp;

    }

}

void CardManage::InitUserCard(User &user){
    int num = 13;
    if(user.type == 1)
        num ++;

    for(int i = 0;i < num; ++i){
        user.cards.push_back(this->random_cards.back());
        this->cards[this->random_cards.back()] --;
        this->random_cards.pop_back();
    }
}


bool CardManage::JudgeWin(User user1){
    
    #ifdef DEBUG
    user1.ShowCard();
    #endif


    vector<int>nums(user1.cards.size());
    map<int,int>nums_map;


    for(int i = 0;i < user1.cards.size(); ++i){
        nums[i] = user1.GetWeight(user1.cards[i]);
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

string CardManage::Distribution(User &user){
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



