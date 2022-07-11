#ifndef INFOMANAGER_H
#define INFOMANAGER_H

#include "tool.h"
#include "Info.h"

class InfoManager{
    string _database_filename;

    vector<Info> _records;

public:
    InfoManager(){ 
        _database_filename = "";
    }

    InfoManager(string database_file){
        _database_filename = database_file;
        InitInfoManager();
    }

    void InitInfoManager(){
        if(_database_filename == ""){
            cout << "没有指定DataBaseFile" << endl;
        }
        else{
            fstream file(_database_filename.c_str(),ios::in | ios::out);
            Info info;
            while(file >> info){
                _records.push_back(info);
            }
        }
        return;
    }


    void AddInfo(Info info){
        _records.push_back(info);
        OutputToFIle(info);
    }


    void DelInfo(Info info){
        for(auto it = _records.begin();it != _records.end(); ){
            if(*it == info){
                it = _records.erase(it);
            }
            else{
                ++ it;
            }
        }
    }

    vector<Info> FindInfo(string webname){
        vector<Info>ret;
        for(auto info : _records){
            if(info.GetWebName() == webname){
                ret.push_back(info);
            }
        }
        return ret;
    }

    void OutputToFIle(Info info){
        fstream file(_database_filename.c_str(),ios::in | ios::out | ios::ate);
        file << info.GetWebName() << endl
             << info.GetAccount() << endl
             << info.GetPassWord() << endl
             << info.GetEmail() << endl;

        file.close();
    }
    void ShowInfo(){
        for(auto info : _records){
            cout << info << endl;
        }
    }

};

#endif
