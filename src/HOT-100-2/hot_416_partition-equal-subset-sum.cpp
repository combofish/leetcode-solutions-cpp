/**
-- question: 分割等和子集
-- method:
 - [ ]
 - [*] 动态规划

--result:

-- analyse:
Time: O( n x target )
Space: O( target )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool canPartition(vector<int> &nums) {
        if (nums.size() < 2) return false;

//        auto sumNum = std::accumulate(nums.cbegin(), nums.cend(), 0);

        int sumNum = 0, maxNum = 0;
        for (auto num: nums) {
            sumNum += num;
            if (num > maxNum) maxNum = num;
        }

        if (sumNum % 2) return false;

        IC(sumNum, maxNum);

        sumNum /= 2;
        IC(sumNum, maxNum);
        if (maxNum > sumNum) return false;

        IC(sumNum, maxNum);

        vector<int> dp(sumNum + 1, 0);
        dp.front() = 1;

        IC(dp);

        for (auto num: nums) {
            for (int j = sumNum; j >=num; j--) {
                dp[j] |= dp[j - num];
            }
        }

        IC(dp);
        return dp.back();


    }

private:


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {1, 5, 11, 5};
    bool ans = true;

    IC(nums, ans);

    IC(solution->canPartition(nums));

    // code end

    return 0;
}


