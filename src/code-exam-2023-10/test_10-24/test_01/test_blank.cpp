#include <icecream.hpp>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]) {
   
    vector<int> nums = {1,4,5,2,3};
    int n = nums.size();

    vector<int> ids(n);
    for(int i = 0; i< n; ++i){
        ids[i] = i;
    }

    std::sort(ids.begin(), ids.end(),[&](int i, int j){
        return nums[i] < nums[j];
    });

    IC(ids);

    int lk = 0;
    int step = 0;
    while(lk < n){
        for(auto &idx: ids){
            if(idx == lk){
                ++lk;
            }
        }
        ++step;
    }

    IC(step - 1);

    return 0;
}
