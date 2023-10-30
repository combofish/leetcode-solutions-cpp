#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();

        int lk = 0, rk = 0;
        int ans = n + 1;


        int cur_sum = 0;
        while (rk < n) {
            while (rk < n && cur_sum < target) {
                cur_sum += nums[rk++];
            }

            IC(rk, cur_sum);

            if (cur_sum == target) {
                ans = std::min(ans, rk - lk + 1);
            } else {
                while (lk < rk && cur_sum >= target) {
                    cur_sum -= nums[lk++];
                }
            }
        }

        if (ans == n + 1) return 0;
        else
            return ans;
    }
};
int main(int argc, char const *argv[]) {
    int target = 7;

    vector<int> nums = {2, 3, 1, 2, 4, 3};

    int ans = 2;
    IC(target, nums, ans);

    Solution sol;
    IC(sol.minSubArrayLen(target, nums));


    return 0;
}
