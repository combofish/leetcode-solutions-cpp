/**
-- question: 找到所有数组中消失的数字
-- method:
 - []

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    vector<int> findDisappearedNumbers(vector<int> &nums) {

        int n = nums.size();
        for (const auto &item: nums) {
            int idx = (item - 1) % n;
            nums[idx] += n;
            IC(nums);
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (nums[i] <= n)
                result.emplace_back(i + 1);

        return result;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> rel = {5, 6};
    IC(nums, rel);

    IC(solution->findDisappearedNumbers(nums));

    // code end

    return 0;
}


