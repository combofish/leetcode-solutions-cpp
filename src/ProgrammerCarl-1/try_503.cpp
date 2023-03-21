/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> record(nums.size(), -1);

        stack<int> sta;
        for (int i = 0; i < nums.size() * 2; i++) {
            while (!sta.empty() && nums[i % nums.size()] > nums[sta.top()]) {
                record[sta.top()] = nums[i % nums.size()];
                sta.pop();
            }
            sta.push(i % nums.size());
        }

        return record;

    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 2, 1};
    vector<int> rel = {2, -1, 2};
    IC(nums, rel);
    IC(solution->nextGreaterElements(nums));


    // code end

    delete solution;
    return 0;
}


