#include <icecream.hpp>
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {

    int n;
    n = 3;

    vector<int> nums(n+1, 0);
//    for(int i = 2; i<=n; ++i){
//        cin>> nums[i];
//    }

    vector<int> p_nums;
    nums = {0,0,1,1};

    p_nums = {0, 1, 1, 1}; // color: 1 - blue, 2 - red;

    unordered_map<int, vector<int>> ump;
    for(int i = 1; i<=n; ++i){
        ump[nums[i]].push_back(i);
    }

    IC(ump);

    vector<bool> used(n+1, false);
    vector<int> recs(n+1, 0);
    for(int i = 1; i<=n; ++i){
        if(!ump.count(i)){
            recs[i] = 1;
            used[i] = true;
        }
    }

    IC(used, recs);

    for(int i = n; i>= 1; --i){
        if(used[i]) continue;

        // un used;
        int cur_val = p_nums[i] == 1 ? 0 : 1;
        for (auto &item: ump[i]){
            if(p_nums[i] == 1){
                cur_val += recs[item];
            }else{
                cur_val *= recs[item];
            }
        }
        used[i] = true;
        recs[i] = cur_val;
    }


    IC(used, recs);

    cout<< recs[1] <<endl;





    return 0;
}
