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
private:


    // function start.
public:

    int jump(vector<int> &nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;
        int ans = 0;
        int nextDistance = 0;
        for (int i = 0; i < nums.size(); i++) {
            nextDistance = std::max(nums[i] + i, nextDistance);
            if (i == curDistance) {
                if (curDistance != nums.size() - 1) {
                    ans++;
                    curDistance = nextDistance;
                    if (nextDistance >= nums.size() - 1) break;
                } else
                    break;
            }
        }

        return ans;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {2, 3, 1, 1, 4};
    int rel = 2;
    IC(nums, rel);

    IC(solution->jump(nums));
    // code end

    delete solution;
    return 0;
}


