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
    int longestOnes(vector<int> &nums, int k) {
        int n = nums.size();

        int left = 0, lsum = 0, rsum = 0;
        int ans = 0;

        vector<int> rsum_vec(n);

        for (int right = 0; right < n; ++right) {
            rsum += 1 - nums[right];

            rsum_vec[right] = rsum;

            while (lsum < rsum - k) {
                lsum += 1 - nums[left];
                ++left;
                IC(left);
            }
            ans = std::max(ans, right - left + 1);
        }

        IC(rsum_vec);
        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int K = 2;
    int ans = 6;

    IC(nums, K, ans);

    IC(solution->longestOnes(nums, K));


    // code end

    return 0;
}