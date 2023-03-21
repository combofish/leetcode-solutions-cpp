/**
-- question: 只出现一次的数字
-- method:
 - [] unordered_map
 - [] unordered_set
 - [] 位运算

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
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> umap;
        for (const auto &item: nums) {

            if (umap.find(item) == umap.end()) {
                umap[item]++;
            } else {
                umap.erase(item);
            }
        }

        assert(umap.size() == 1);
        return umap.begin()->first;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {4, 1, 2, 1, 2};
    int rel = 4;

    IC(nums, rel);

    IC(solution->singleNumber(nums) == rel);
    // code end

    return 0;
}


