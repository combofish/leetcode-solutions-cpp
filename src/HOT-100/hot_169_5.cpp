/**
-- question: 多数元素
-- method:
 - [] 哈希表
 - [] 排序
 - [] 随机化
 - [] 分治
 - [*] Boyer-Moore 投票算法

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int majorityElement(vector<int> &nums) {
        int candidate = -1;
        int count = 0;
        for (const auto &item: nums) {
            if (item == candidate) ++count;
            else if (--count < 0) {
                candidate = item;
                count = 1;
            }
        }
        return candidate;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int rel = 2;

    IC(nums, rel);
    IC(solution->majorityElement(nums) == rel);

    // code end

    return 0;
}


