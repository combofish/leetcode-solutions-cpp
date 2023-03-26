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

    int n = 7;
    vector<int> nums = {3, 1, 2, 7, 10, 2, 4};

    IC(nums, n);

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (i <= 2) dp[i] = std::max(dp[i - 1], nums[i]);
        else {
            dp[i] = dp[i-3] + nums[i-1];
        }

    }

    IC(dp);


    return 0;
}

/**
7
3 1 2 7 10 2 4

 14



     vector<int> dp(n + 1, 0);
    dp.front() = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {

            dp[j] = std::max(dp[j-3] + nums[j]);
        }
        IC(dp);
    }

    IC(dp);
*/