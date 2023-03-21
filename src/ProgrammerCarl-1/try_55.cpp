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
//    bool canJump(vector<int> &nums) {
//        vector<bool> canReach(nums.size(), false);
//        canReach.front() = true;
//
//        IC(canReach);
//        for (int i = 0; i < nums.size(); i++) {
//            if (canReach[i]) {
//                for (int k = 1; k <= nums[i] && i + k < nums.size(); k++) {
//                        canReach[i + k] = true;
//                }
//
//                IC(i, canReach);
//            }
//        }
//
//        return canReach.back();
//
//    }

    bool canJump(vector<int> &nums) {
        int cover = 0;
        if (nums.size() == 1) return true;
        for(int i = 0; i<= cover; i++){
            cover = std::max(cover, i + nums[i]);
            if(cover >= nums.size() -1) return true;
        }

        return false;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {2, 3, 1, 1, 4};
    bool rel = true;

    IC(nums, rel);
    IC(solution->canJump(nums));
    // code end

    delete solution;
    return 0;
}


