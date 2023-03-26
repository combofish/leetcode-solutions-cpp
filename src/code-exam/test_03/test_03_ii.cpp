//
// Created by larry on 23-3-25.
//

//
// Created by larry on 23-3-25.
//

#include <iostream>
#include <vector>
#include <stack>

// #include <icecream.hpp>
// #include "combofish_utils.hpp"

using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    vector<int> nums(m, 0);
    vector<int> qNums(n, 0);


    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> qNums[i];
    }
    for (auto &num: nums) num *= num;

    for (auto &bs: qNums) {
        vector<int> dp(bs + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = bs; j >= nums[i]; j--) {
                dp[j] = std::max(dp[j], dp[j - i] + 1);
            }
        }

    }


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