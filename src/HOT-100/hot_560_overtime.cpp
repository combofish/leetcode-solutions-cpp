/**
-- question: 和为K的子数组
-- method:
 - [] 枚举
 - [] 枚举

--result:

-- analyse:
Time: O(n^2)
Space: O(1)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int subarraySum(vector<int> &nums, int k) {
        result = 0;
        for (int i = 0; i < nums.size(); i++) {
            backtracking(nums, k, i);
        }
        return result;
    }

private:
    int result;

    void backtracking(const vector<int> &nums, int k, int idx) {
        int sum = 0;
        for (int i = idx; i < nums.size(); i++) {
            IC(idx, i);
            sum += nums[i];
            if (sum == k) result++;
        }
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int rel = 2;
    IC(nums, k, rel);
    IC(solution->subarraySum(nums, k) == rel);

    // code end

    return 0;
}


