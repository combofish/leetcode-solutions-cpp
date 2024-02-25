#include <bits/stdc++.h>
#include <icecream.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();

        for (auto &num: nums) {
            if (num <= 0) num = n + 1;
        }

        IC(nums);

        // for(auto &num: nums){
        //     if(num <= n) nums[num - 1] *=-1;
        // }

        for (int i = 0; i < n; ++i) {
            auto num = std::abs(nums[i]);
            if(num <= n) nums[num - 1] = - std::abs(nums[num - 1]);

            // if (nums[i] <= n) nums[nums[i] - 1] *= -1;

            IC(i, nums);
        }

        IC(nums);

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};
int main() {

    // vector<int> nums = {1, 2, 0};
    // int ans = 3;

    vector<int> nums = {3,4,-1,1};
    int ans = 2;

    IC(nums, ans);
    Solution sol;

    IC(sol.firstMissingPositive(nums));



    return 0;
}