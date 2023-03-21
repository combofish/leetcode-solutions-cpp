/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> umap;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (umap.find(target - n) != umap.end()) {
                res.emplace_back(umap[target - n]);
                res.emplace_back(i);
                return res;
            } else {
                umap[n] = i;
            }

            IC(umap);
        }

        return res;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vec_t nums = {2, 7, 11, 15};
    int target = 26;

    IC(nums, target, solution->twoSum(nums, target));
    // code end

    delete solution;
    return 0;
}
