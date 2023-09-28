#include <iostream>
#include <vector>
#include <unordered_map>
#include <icecream.hpp>

using namespace std;

inline bool is_same_val(unordered_map<char, int> &a, unordered_map<char, int> &b){
    if(a.size() != b.size()) return false;

    for(auto &item: b){
        if(a[item.first] != item.second){
            return false;
        }
    }

    return true;
}

int main(){

    vector<string> strs = {"abcbd", "dbcba","aa","aa"};

    int n = strs.size();

    vector<unordered_map<char, int>> umps;

    for(auto &str: strs){
        unordered_map<char, int> ump;

        for(auto &c: str){
            ++ump[c];
        }

        umps.emplace_back(ump);
    }

    IC(umps);


    int cnt = 0;
    for(int i = 0; i< n; ++i){
        for(int j = i + 1; j < n; ++j){

            if(is_same_val(umps[i], umps[j])){
                ++cnt;
            }


        }
    }

    cout<<cnt<<endl;




    return 0;
}