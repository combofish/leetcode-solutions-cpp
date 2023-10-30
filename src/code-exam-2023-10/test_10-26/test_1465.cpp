#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {
    void expand(unordered_set<int> &uet, vector<int> &nums, int limit) {
        nums.insert(nums.begin(), 0);
        nums.emplace_back(limit);

        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            uet.insert(nums[i] - nums[i - 1]);
        }
    }

public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {

        unordered_set<int> uet_col, uet_row;
        expand(uet_col, horizontalCuts, h);
        expand(uet_row, verticalCuts, w);
        const int MOD = 1e9 + 7;

        IC(uet_col, uet_row);

        int ans = 0;
        for (auto &i: uet_col) {
            for (auto &j: uet_row) {
                long long tmp = ((long long) i * j) % MOD;
                IC(tmp);
                ans = std::max(ans, i * j);
            }
        }

        return ans;
    }
};
int main(int argc, char const *argv[]) {
    int h = 1000000000, w = 1000000000;
    vector<int> nums = {2};
    vector<int> nums2 = {2};

    int ans = 81;

    IC(h, w, nums, nums2, ans);

    Solution sol;

    IC(sol.maxArea(h, w, nums, nums2));


    return 0;
}
