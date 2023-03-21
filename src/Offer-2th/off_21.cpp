/**
-- question: 调整数组顺序使奇数位于偶数前面
-- method:
 - [*] 两次遍历
 - [ ] 双指针 + 一次遍历
 - [ ] 原地交换

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> exchange(vector<int> &nums) {
        auto result = vector<int>();
        for (const auto &n: nums)
            if (n % 2) {
                result.emplace_back(n);
            }

        for (const auto &n: nums)
            if (n % 2 == 0) result.emplace_back(n);
        return result;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 2, 3, 4};
    vector<int> rel = {1, 3, 2, 4};
    IC(nums, rel);
    IC(solution->exchange(nums));
    // code end

    return 0;
}
