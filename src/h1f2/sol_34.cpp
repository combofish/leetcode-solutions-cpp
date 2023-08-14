/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:

    vector<int> searchRange(vector<int>& nums, int target) {

        auto lower = binarySearch(nums, 0, nums.size() -1, target, true);
        auto bigger = binarySearch(nums, 0, nums.size() - 1, target, false);



    }

private:
    int binarySearch(vector<int> &nums, int lk, int rk, int target, bool lower){
        bool ans = -1;
        while(lk <= rk){
            auto mid = (lk + rk) >> 1;

            if(target < nums[mid] || (lower && target <= nums[mid])){
                ans = mid;

            }
        }

        return ans;

    }


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    // code end

    return 0;
}