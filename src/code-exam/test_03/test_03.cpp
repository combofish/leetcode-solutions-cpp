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

    int n = 5;
    vector<int> nums = {1, 2, 2, 4, 5},
            bagSize = {1, 3, 7, 9, 15};


    IC(nums, n, bagSize);

    int bs = 1;
    int ans = 3;
    IC(bs, ans);

    /// int res = 0;
    for (auto &num: nums) num *= num;
    IC(nums);


    vector<int> dp(bs+1, 0);

    for(int i = 0; i<n; i++){
        for(int j = bs; j>=nums[i]; j--){
            dp[j] = std::max(dp[j], dp[j - nums[i]] + 1);
        }

        IC(dp);
    }

    IC(dp);

    return 0;
}

/**
5 5
1 2 2 4 5
1 3 7 9 15
样例输出
1 1 2 3 3



//    vector<int> dp(bs+1,0);
    vector<vector<int>> dp(bs + 1, vector<int>(2, 0));

    dp.front().front() = 1;
    for (int i = 1; i <= bs; i++) {
        for (int j = bs; j >= i; j--) {
            dp[j] = std::max(dp[j], dp[j - i] + 1);

        }
    }
*/