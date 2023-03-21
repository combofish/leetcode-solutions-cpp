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
        val.resize(n + 2);
        for (int i = 1; i <= n; i++) val[i] = nums[i - 1];

        val.front() = val.back() = 1;

        rec.resize(n + 2, vector<int>(n + 2, -1));

        auto result = solve(0, n + 1);
        IC(result, rec, val);
        return result;
    }

private:
    vector<vector<int>> rec;
    vector<int> val;

    int solve(int l, int r) {
        //  IC(l, r, rec, val);
        IC(l, r);

        if (l >= r - 1) return 0;
        if (rec[l][r] != -1) return rec[l][r];

        for (int i = l + 1; i < r; i++) {
            int sum = val[l] * val[i] * val[r];
            sum += solve(l, i) + solve(i, r);
            rec[l][r] = std::max(sum, rec[l][r]);
        }
        return rec[l][r];
    }
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
