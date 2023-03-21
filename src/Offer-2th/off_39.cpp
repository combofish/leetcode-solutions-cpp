/**
-- question: 数组中出现次数超过一半的数字
-- method:
 - [*] 哈希表
 - [ ] 排序
 - [ ] 随机化 -- * --
 - [ ] 分治
 - [ ] Boyer-Moore 投票算法 -- * --

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int majorityElement(vector<int> &nums) {
        int cnt = 0;
        int majority = 0;
        auto cache = unordered_map<int, int>();

        for (const auto &n: nums) {
            ++cache[n];

            if (cache[n] > cnt) {
                cnt = cache[n];
                majority = n;
            }
        }

        return majority;
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
