/**
-- question: 和为K的子数组
-- method:
 - [ ] 枚举
 - [*] 前缀和 + 哈希表优化

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

    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int cnt = 0, pre = 0;
        for (auto &n: nums) {
            pre += n;
            if (ump.count(pre - k)) cnt += ump[pre - k];

            IC(n, pre, pre - k, ump);
            ump[pre]++;
        }
        return cnt;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
//    vector<int> nums = {1, 2, 3};
//    int k = 3;
//    int ans = 2;

    vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};
    int k = 7;
    int ans = 4;
    IC(nums, k, ans);

    IC(solution->subarraySum(nums, k));

    // code end

    return 0;
}


