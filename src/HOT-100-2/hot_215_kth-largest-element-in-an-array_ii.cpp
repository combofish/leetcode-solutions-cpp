/**
-- question: 数组中的第K个最大元素
-- method:
 - [ ] 基于快速排序的选择方法
 - [-] 基于堆排序的选择方法

--result:

-- analyse:
Time: O(nlog(n))
Space: O(log(n))
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int findKthLargest(vector<int> &nums, int k) {
        std::priority_queue<int> pqu;

        for(auto &num: nums)
            pqu.push(num);

        while(--k){
            pqu.pop();
        }

        return pqu.top();

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    int ans = 4;

    IC(nums, k, ans);

    IC(solution->findKthLargest(nums, k));
    // code end

    return 0;
}
