/**
-- question: 滑动窗口最大值
-- method:
 - [ ] 优先队列
 - [*] 单调队列
 - [ ] 分块 + 预处理
 
--result:

-- analyse:
Time: O( n )
Space: O(k)
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
        std::deque<int> qu;
        for (int i = 0; i < k; i++) {
            while (!qu.empty() && nums[i] >= nums[qu.back()]) qu.pop_back();
            qu.push_back(i);
        }

        vector<int> ans = {nums[qu.front()]};
        for (int i = k; i < n; i++) {
            while (!qu.empty() && nums[i] > nums[qu.back()]) {
                qu.pop_back();
            }
            qu.emplace_back(i);
            while (qu.front() <= i - k) qu.pop_front();

            ans.emplace_back(nums[qu.front()]);
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
