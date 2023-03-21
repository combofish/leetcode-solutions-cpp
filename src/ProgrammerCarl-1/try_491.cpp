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
private:

    vector<int> path;
    vector<vector<int>> result;

//    void backtracking(vector<int> &nums, int startIndex) {
//        if (path.size() >= 2) result.push_back(path);
//        if (startIndex >= nums.size()) return;
//
//        unordered_set<int> uset;
//        for (int i = startIndex; i < nums.size(); i++) {
//
//            if ((path.empty() || path.back() <= nums[i]) &&
//                (uset.find(nums[i]) == uset.end())) {
//                uset.insert(nums[i]);
//                path.push_back(nums[i]);
//                backtracking(nums, i + 1);
//                path.pop_back();
//            }
//        }
//    }

    void backtracking(vector<int> &nums, int startIndex) {
        if (path.size() >= 2) result.push_back(path);
        if (startIndex >= nums.size()) return;

        int used[201] = {0};
        for (int i = startIndex; i < nums.size(); i++) {

            if ((path.empty() || path.back() <= nums[i]) &&
                (used[nums[i] + 100] != 1)) {

                used[nums[i] + 100] = 1;
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
        }
    }

    // function start.
public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> rel = {{4, 6},
                               {4, 6, 7},
                               {4, 6, 7, 7},
                               {4, 7},
                               {4, 7, 7},
                               {6, 7},
                               {6, 7, 7},
                               {7, 7}
    };

    IC(nums, rel);
    IC(solution->findSubsequences(nums));

    // code end

    delete
            solution;
    return 0;
}


