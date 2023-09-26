#include <iostream>
#include <vector>
#include <algorithm>
#include <icecream.hpp>
using namespace std;

bool can_find;

void backtracking(vector<int> &nums, int target, int sum, int startIdx){
    if(sum == target){
        can_find = true;
        return;
    }

    if(can_find) return;

    for(int i = startIdx; i< nums.size() && sum + nums[i] <= target; ++i){

        backtracking(nums, target, sum + nums[i], i + 1);

        if(can_find) return;
    }
}
int main() {

    vector<int> nums = {3, 1, 6, 2};

    int max_val = nums.front();
    int sum_val = 0;
    for(auto &ele: nums){
        max_val = std::max(ele, max_val);
        sum_val += ele;
    }

    if(sum_val % 2 == 1) {
        cout<<0<<endl;
        return 0;
    }

    int half = sum_val / 2;
    if(max_val > half){
        cout<< 0<<endl;
        return 0;
    }


    can_find = false;
    
    std::sort(nums.begin(), nums.end());

    // backtracking(nums, half, 0, 0);

    vector<int> dp(half+1, 0);
    dp.front() = 1;

    int n = nums.size();
    for(int i = 0; i< n; ++i){
        for(int j = half; j>= nums[i]; --j){
            dp[j] += dp[j - nums[i]];
        }
    }

    IC(dp);


    if(can_find){
        cout<< 1<<endl;
    }else{
        cout<< 0<<endl;
    }






    return 0;
}