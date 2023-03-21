/**
-- question: 数组中出现次数超过一半的数字
-- method:
 - [ ] 哈希表
 - [ ] 排序
 - [ ] 随机化 -- * --
 - [ ] 分治
 - [*] Boyer-Moore 投票算法 -- * --

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int majorityElement(vector<int> &nums) {
        int candidate = -1;
        int cnt = 0;
        for (const auto &n: nums) {
            if (candidate == n) ++cnt;
            else if (--cnt < 0) {
                candidate = n;
                cnt = 1;
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
    vector<int> result = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int rel = 2;
    IC(result, rel);
    IC(solution->majorityElement(result) == rel);
    // code end

    return 0;
}
