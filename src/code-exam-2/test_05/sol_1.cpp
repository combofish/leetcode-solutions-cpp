#include <iostream>
#include <icecream.hpp>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main(){

    int n = 4;
    vector<int> nums = {1,2,3,4};

    unordered_map<int,long long> ump, tmp_ump;

    ump[nums.back()] = 1;
    nums.pop_back();

    const long long MOD = 1e9 + 7;

    for(int i = 1; i< n; ++i){
        auto x = nums.back(); nums.pop_back();
        tmp_ump.clear();

        for(const auto & item: ump){
            auto m1 = (item.first + x) % 10;
            auto m2 = (item.first * x) % 10;

            tmp_ump[m1] += item.second;
            tmp_ump[m2] += item.second;

            tmp_ump[m1] %= MOD;
            tmp_ump[m2] %= MOD;
        }

        ump = tmp_ump;
        IC(ump);

    }

    IC(nums);

    for(int i = 0; i< 10 ; ++i){
        cout<<ump[i]<<" ";
    }
    cout<<endl;

    IC(MOD);

    return 0;
}