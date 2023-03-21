/**
-- question: 移动零
-- method:
 - [] single point
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
    void moveZeroes(vector<int> &nums) {
        int idx = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                std::swap(nums[i], nums[++idx]);
            }
            IC(nums, i, idx);
        }


        for (int & num : nums) {
            IC(num);
        }

        for (const auto &item: nums) {
            IC(item);
        }
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {0, 1, 0, 3, 12};
    vector<int> rel = {1, 3, 12, 0, 0};
    IC(nums, rel);

    solution->moveZeroes(nums);
    IC(nums);

    // code end

    return 0;
}


