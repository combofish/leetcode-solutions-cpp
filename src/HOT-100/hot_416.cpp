/*
 * @Author: combofish combofish@139.com
 * @Date: 2022-12-03 21:37:29
 * @LastEditors: combofish combofish@139.com
 * @LastEditTime: 2022-12-04 08:16:17
 * @FilePath: /Leetcode-Solution-Cpp/src/HOT-100/hot_416.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
-- question: 分割等和子集
-- method:
 - [] 动态规划

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    bool canPartition(vector<int> &nums) {
        if (nums.size() <= 1) return false;

        int numsSum = 0, maxNum = 0;
        for (const auto &item: nums) {
            numsSum += item;
            if (item > maxNum) maxNum = item;
        }
        if (numsSum % 2) return false;
        const int midSum = numsSum >> 1;

        if (maxNum > midSum) return false;

        vector<int> dp(midSum + 1, 0);
        for (const auto &item: nums)
            for (int j = midSum; j >= item; j--)
                dp[j] = std::max(dp[j], dp[j - item] + item);

        return dp.back() == midSum;
        
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {14, 9, 8, 4, 3, 2};
    bool rel = true;

    IC(nums, rel);
    IC(solution->canPartition(nums) == rel);

    // code end

    return 0;
}


