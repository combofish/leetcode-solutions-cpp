#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;


int main(int argc, char const *argv[]) {
    int n = 6, k = 3;

    vector<int> nums = {
            13,
            5,
            1,
            8,
            21,
            2};

    IC(nums, n, k);

    unordered_map<int, pair<int, int>> ump;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            auto diff = std::abs(nums[i] - nums[j]);
            if(ump.count(diff)) continue;
            else{
                ump[diff] = make_pair(i, j);
            }
        }
    }

    IC(ump);

    vector<pair<int, pair<int,int>>> cache(ump.begin(), ump.end());
    std::sort(cache.begin(), cache.end());

    IC(cache);

    unordered_set<int> uet;
    auto ans = cache.back().first;

    while(uet.size() < k){
        auto node = cache.back();
        cache.pop_back();

        auto ij = node.second;
        auto i = ij.first, j = ij.second;

        if(!uet.count(i) && !uet.count(j) && uet.size() < k) {
            uet.insert(i);
            uet.insert(j);

            ans = std::min(ans, node.first);
        }

        // if(!uet.count(j) && uet.size() < k) uet.insert(j);
    }

    // vector<int> ans;

    // for(auto &i: uet){
    //     ans.emplace_back(nums[i]);
    //     if(ans.size() >= k) break;
    // }

    IC(ans);



    return 0;
}


/***
 * 
 * 
 * 
 * 
 * 6 3
13 5 1 8 21 2


8


13 5 21 
13 1 21 
13 21 2
*/