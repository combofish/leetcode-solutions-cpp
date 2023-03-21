/**
-- question: 多数元素
-- method:
 - [] 哈希表
 - [] 排序
 - [] 随机化
 - [] 分治
 - [] Boyer-Moore 投票算法

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> umap;
        int majority = 0, cnt = 0;
        for (const auto &item: nums){
            umap[item]++;
            if(umap[item] > cnt){
                cnt = umap[item];
                majority = item;
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
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int rel = 2;

    IC(nums, rel);
    IC(solution->majorityElement(nums) == rel);

    // code end

    return 0;
}


