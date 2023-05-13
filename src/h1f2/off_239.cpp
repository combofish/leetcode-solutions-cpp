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
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();

        vector<int> left(n), right(n);

        for (int i = 0; i < n; ++i) {
            if (i % k == 0) {
                left[i] = nums[i];
            } else {
                left[i] = std::max(left[i - 1], nums[i]);
            }
        }

        IC(left);

        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1 || (i + 1) % k == 0) right[i] = nums[i];
            else right[i] = std::max(right[i + 1], nums[i]);
        }

        IC(right);

        vector<int> ans;
        for (int i = 0; i <= n-k; ++i) {
            ans.push_back(std::max(right[i], left[i + k - 1]));
        }

        return ans;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    IC(nums, k);
    vector<int> ans = {3, 3, 5, 5, 6, 7};

    IC(nums, ans);
    IC(solution->maxSlidingWindow(nums, k));
    // code end

    return 0;
}