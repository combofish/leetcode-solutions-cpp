#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int n = nums.size();
        IC(n);

        int lk = 0, rk = n-1, ans = n;

        // int lk = 0, rk = nums.size() - 1, ans = nums.size();

        // while(lk <= rk){
        //     auto mid = ((rk - lk) >> 1) + lk;
        //     if(target <= nums[mid]){
        //         ans = mid;
        //         rk = mid - 1;
        //     }else{
        //         lk = mid + 1;
        //     }
        // }

        while (lk <= rk) {
            auto mid = ((rk - lk) >> 1) + lk;
            IC(lk, rk, mid, nums[mid], target);

            if (target >= nums[mid]) {
                ans = mid;
                lk = mid + 1;
            } else {
                rk = mid - 1;
            }
            IC(lk, rk, mid, nums[mid], target);
        }

        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    vector<int> nums = {1, 3, 5, 6};
    
    // int target = 2;
    int target = 5;

    int ans = 1;

    IC(nums, target, ans);

    IC(sol.searchInsert(nums, target));

    return 0;
}
