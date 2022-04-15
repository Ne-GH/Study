#include "./User.h"


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

User::User(){
    id = 0;
    type = 0;
    name = "user1";
}

User::User(int type){
    id = 0;
    this->type = type;
}

int User::GetWeight(string str){
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

bool User::card_sort_cmp(string str1,string str2){
    return GetWeight(str1) < GetWeight(str2);
}

void User::card_sort(){
    sort(this->cards.begin(),this->cards.end(),this->card_sort_cmp);
}

string User::push(int pos){

    if(pos < 0 || pos >= this->cards.size()){
        cout << "pos is error !!!" << endl;
    }
    string ret_card = *(this->cards.begin()+pos);
    this->cards.erase(this->cards.begin()+pos);

    return ret_card;
}

void User::push(string cardname){
    auto pos = find(this->cards.begin(),this->cards.end(),cardname);
    if(pos == this->cards.end()){
        cout << "this card not found" << endl;
    }
    this->cards.erase(pos);
}

void User::ShowCard(){
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
