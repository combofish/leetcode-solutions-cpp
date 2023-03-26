//
// Created by larry on 23-3-25.
//

#include <iostream>
#include <vector>
#include <stack>

#include <icecream.hpp>
#include "combofish_utils.hpp"

using namespace std;

int main() {

    string s = "LOGNAME=default;SHELL=/bin/bash;HOME=/home/xiaomei;LOGNAME=xiaomei;";


    string tmp = "";
    vector<string> rec;
    for (auto &c: s) {
        if (c == ';') {
            rec.emplace_back(tmp);
            tmp.clear();
            continue;
        }
        tmp.push_back(c);
    }

    IC(rec);


    std::unordered_map<string, vector<string>> ump;
    for (auto &item: rec) {
        tmp.clear();
        string key_s = "";
        for (auto &c: item) {
            if (c == '=') {
                key_s = tmp;
                tmp.clear();
                break;
            }
            tmp.push_back(c);
        }
        ump[key_s].emplace_back(item.substr(key_s.size()+1));
    }

    IC(ump);

    string qs = "SHELL";

    cout<< ump[qs].back() <<endl;

    return 0;
}

/**
 *
LOGNAME=default;SHELL=/bin/bash;HOME=/home/xiaomei;LOGNAME=xiaomei;
4
SHELL
HOME
LOGNAME
logname
样例输出
/bin/bash
/home/xiaomei
xiaomei
EMPTY

*/