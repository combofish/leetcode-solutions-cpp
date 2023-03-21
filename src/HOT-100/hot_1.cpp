/**
-- method:

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

    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            if (umap.find(nums[i]) != umap.end()) {
                return {umap[tmp], i};
            } else {
                umap[tmp] = i;
            }
            IC(umap);
        }

        return {-1, -1};
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> rel = {0, 1};

    IC(solution->twoSum(nums, target));

    // code end

    delete solution;
    return 0;
}


