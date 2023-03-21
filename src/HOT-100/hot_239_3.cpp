/**
-- question: 滑动窗口最大值
-- method:
 - [ ] 优先队列
 - [ ] 单调队列
 - [*] 分块 + 预处理
 
--result:

-- analyse:
Time: O( n )
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <deque>
#include <queue>

class Solution {

    // function start.
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        auto prefixMax = vector<int>(n);
        auto suffixMax = vector<int>(n);

        for (int i = 0; i < n; ++i) {
            if (i % k) prefixMax[i] = std::max(prefixMax[i - 1], nums[i]);
            else
                prefixMax[i] = nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1 || (i+1) % k == 0) suffixMax[i] = nums[i];
            else
                suffixMax[i] = std::max(suffixMax[i + 1], nums[i]);
        }

        IC(prefixMax, suffixMax);

        auto ans = vector<int>();
        for (int i = 0; i <= n - k; i++) {

            ans.emplace_back(std::max(suffixMax[i], prefixMax[i + k - 1]));
            IC(i, i + k - 1);
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
    auto res = {3, 3, 5, 5, 6, 7};
    IC(nums, k, res);

    IC(solution->maxSlidingWindow(nums, k));

    // code end

    return 0;
}
