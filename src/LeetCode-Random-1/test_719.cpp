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
public:
    // function start.
    int smallestDistancePair(vector<int> &nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums.back() - nums.front();
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                int i = std::lower_bound(nums.begin(), nums.begin() + j, nums[j] - mid)
                        - nums.begin();
                cnt += j - i;
            }
            if (cnt >= k)
                right = mid - 1;
            else left = mid + 1;

        }
        return left;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 6, 1};
    int k = 3;
    int ret = 5;
    IC(nums, k, ret);
    IC(solution->smallestDistancePair(nums, k));
    // code end

    delete solution;
    return 0;
}
