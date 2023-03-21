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
    static bool cmp(int a, int b) {
        return std::abs(a) > std::abs(b);
    }
    // function start.
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        std::sort(nums.begin(), nums.end(), cmp);

        IC(nums);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }

        if (k % 2) nums.back() *= -1;

        return std::accumulate(nums.begin(), nums.end(), 0);

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {4, 2, 3};
    int k = 1;

    IC(nums, k);
    IC(solution->largestSumAfterKNegations(nums, k));
    // code end

    delete solution;
    return 0;
}


