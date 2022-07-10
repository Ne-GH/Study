#ifndef INFOMANAGER_H
#define INFOMANAGER_H

#include "tool.h"
#include "Info.h"
#include <vector>

class InfoManager{
    string _database_filename;

    vector<Info> _records;

public:
    InfoManager(){  }

    void SetDatabaseFilename(string database_file){
        _database_filename = database_file;
    }


    void AddInfo(Info info){
        _records.push_back(info);
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

};

#endif
