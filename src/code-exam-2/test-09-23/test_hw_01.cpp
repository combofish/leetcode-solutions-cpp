#include <vector>
#include <string>
#include <icecream.hpp>


using namespace std;

string remove_first_zero(const string &str){
    int sz = str.size();
    int rk = 0;
    while(rk < sz && str[rk] == '0'){
        ++rk;
    }

    return str.substr(rk);
}

int main(){


    vector<string> strs = {
        "1.2.02555",
        "1.2.2555",
        "1.2.ABA",
        "1.2.0ABA",
        "1.2.0ABA.c"
    };


    IC(strs);


    vector<vector<string>> s_strs;
    
    for(auto &str: strs){
        string tmp_str;
        stringstream ss(str);
        vector<string> cur_strs;

        while(std::getline(ss, tmp_str, '.')){
            cur_strs.emplace_back(tmp_str);
        }

        // case 1
        if(cur_strs.size() != 3) continue;

        // case 2
        int sz = cur_strs.back().size();
        bool need_skip = false;
        for(int i = 0; i + 1 < sz; ++i){
            if(cur_strs.back()[i] == 'r' && cur_strs.back()[i+1] == 'c'){
                need_skip = true;
                break;
            }
        }
        if(need_skip) continue;


        // case 3
        string bak_first = "";
        for (auto &c: cur_strs.front()){
            if(!std::isalpha(c)){
                bak_first += c;
            }
        }
        if(bak_first.empty()) continue;

        string bak_second = "";
        for(auto &c: cur_strs[1]){
            if(!std::isalpha(c)){
                bak_second += c;
            }
        }
        if(bak_second.empty()) continue;

        cur_strs[0] = bak_first;
        cur_strs[1] = bak_second;

        // remove zero
        // case 5
        need_skip = false;
        for(auto &item: cur_strs){
            item = remove_first_zero(item);
            if(item.empty()){
                need_skip = true;
            }
        }
        if(need_skip) continue;


        // case 4
        if(!s_strs.empty()){
            auto last = s_strs.back();

            bool is_same = true;
            for(int i = 0; i< 3; ++i){
                if(last[i] != cur_strs[i]){
                    is_same = false;
                }
            }

            if(is_same) continue;
            else{
                s_strs.emplace_back(cur_strs);
            }
        }else{
            s_strs.emplace_back(cur_strs);
        }
    }

    IC(s_strs);

    int len = s_strs.size();
    for(int i = 0; i< len-1; ++i){
        cout<< s_strs[i][0]<< '.';
        cout<< s_strs[i][1]<< '.';
        cout<< s_strs[i][2];

        cout<<' ';
    }

    cout<< s_strs[len-1][0]<< '.';
    cout<< s_strs[len-1][1]<< '.';
    cout<< s_strs[len-1][2];

    cout<<endl;


    return 0;
}