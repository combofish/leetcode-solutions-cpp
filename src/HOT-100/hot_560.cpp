/**
-- question: 和为K的子数组
-- method:
 - []
 - [] 前缀和 + 哈希表优化

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = 1;
        int count = 0, pre = 0;
        for (const auto &item: nums) {
            pre += item;
            if (umap.find(pre - k) != umap.end()) {
                count += umap[pre - k];
            }
            umap[pre]++;
        }

        IC(umap);
        return count;
    }

private:


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int rel = 2;
    IC(nums, k, rel);
    IC(solution->subarraySum(nums, k) == rel);

    // code end

    return 0;
}


