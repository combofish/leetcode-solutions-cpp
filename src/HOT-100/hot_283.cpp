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

        for (const auto &item: nums) {
            if (item != 0) {
                nums[++idx] = item;
            }

            IC(nums);
        }

        while(++idx < nums.size()){
            nums[idx] = 0;
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


