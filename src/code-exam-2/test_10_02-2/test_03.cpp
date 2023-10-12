#include <icecream.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;
    string tmp;
    // cin>>line;
    line = "1,3,2,8,4,9";

    stringstream ss(line);
    vector<int> nums;

    while (getline(ss, tmp, ',')) {
        nums.emplace_back(stoi(tmp));
    }

    IC(nums);
    int fee;
    int ans = 0;
    // cin>>fee;
    fee = 2;

    int sz = nums.size();
    vector<vector<int>> dp(sz, vector<int>(2, 0));
    dp.front().front() -= nums.front();

    for (int i = 1; i < sz; ++i) {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - nums[i]);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + nums[i] - fee);
    }


    IC(dp);
    cout << std::max(dp.back().front(), dp.back().back()) << endl;

    return 0;
}
