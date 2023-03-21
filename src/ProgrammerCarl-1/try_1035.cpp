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
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); i++)
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }

        return dp.back().back();

    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums1 = {1, 4, 2};
    vector<int> nums2 = {1, 2, 4};
    int rel = 2;
    IC(nums1, nums2, rel);
    IC(solution->maxUncrossedLines(nums1, nums2) == rel);

    // code end

    delete solution;
    return 0;
}


