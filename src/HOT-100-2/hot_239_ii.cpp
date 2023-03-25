/**
-- question: 滑动窗口最大值
-- method:
 - [ ] 优先队列
 - [*] 单调队列
 - [ ] 分块 + 预处理

--result:

-- analyse:
Time: O( n )
Space: O( k )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        std::deque<int> dq;
        for(int i = 0; i< k; i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);
        }

        IC(dq);
        vector<int> ans = {nums[dq.front()]};
        for(int i = k; i< n; i++){
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);

            while(dq.front() <= i-k) dq.pop_front();

            ans.emplace_back(nums[dq.front()]);
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

    vector<int> ans = {3, 3, 5, 5, 6, 7};
    IC(nums, k, ans);

    IC(solution->maxSlidingWindow(nums, k));
    // code end

    return 0;
}


