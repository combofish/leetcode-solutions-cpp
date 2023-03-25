/**
-- question: 滑动窗口最大值
-- method:
 - [*] 优先队列
 - [ ] 单调队列
 - [ ] 分块 + 预处理

--result:

-- analyse:
Time: O( nlog(n) )
Space: O( n )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        std::priority_queue<pair<int,int>> pqu;
        for(int i =0;  i< k;i++) pqu.emplace(nums[i],i);

        vector<int> ans{pqu.top().first};
        for(int i = k; i< n; i++){
            pqu.emplace(nums[i], i);
            while(pqu.top().second <= i - k) pqu.pop();

            ans.emplace_back(pqu.top().first);
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


