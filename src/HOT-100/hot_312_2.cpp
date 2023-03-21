/**
-- question: 戳气球
-- method:
 - [*] 记忆化搜索
 - [ ] 动态规划
 
--result:

-- analyse:
Time: O(n^3)
Space: O(n^2)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        auto rec = vector<vector<int>>(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);

        val.back() = val.front() = 1;
        for (int i = 1; i <= n; i++) val[i] = nums[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = std::max(rec[i][j], sum);
                }
            }
        }
        IC(val, rec);
        return rec.front().back();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {3, 1, 5, 8};
    int rel = 167;

    IC(nums, rel);
    IC(solution->maxCoins(nums));
    // code end

    return 0;
}
