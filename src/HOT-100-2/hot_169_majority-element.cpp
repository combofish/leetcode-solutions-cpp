/**
-- question: 多数元素
-- method:
 - [-] 哈希表
 - [ ] 排序
 - [ ] 随机化
 - [ ] 分治
 - [*] Boyer-Moore 投票算法

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> ump;
        for (auto num: nums) {
            ump[num]++;
        }

        int n = nums.size() / 2;
        for (auto &item: ump) {
            if (item.second > n) return item.first;
        }

        return -1;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int ans = 2;
    IC(nums, ans);

    IC(solution->majorityElement(nums));


    // code end

    return 0;
}


