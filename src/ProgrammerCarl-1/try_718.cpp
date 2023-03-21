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
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= nums1.size(); i++)
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > result) result = dp[i][j];
            }

        return result;
    }

    int findLength_2(vector<int> &nums1, vector<int> &nums2) {
        vector<int> dp(vector<int>(nums2.size()+1, 0));
        int result = 0;
        for (int i = 1; i <= nums1.size(); i++)
            for (int j = nums2.size(); j > 0; j--) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[j] = dp[j - 1] + 1;
                else dp[j] = 0;
                if (dp[j] > result) result = dp[j];
            }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    int rel = 3;

    IC(nums1, nums2, rel);

    IC(solution->findLength(nums1, nums2) == rel);
    IC(solution->findLength_2(nums1, nums2) == rel);
    // code end

    delete solution;
    return 0;
}


