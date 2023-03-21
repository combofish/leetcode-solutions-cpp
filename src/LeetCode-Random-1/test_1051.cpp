/**
-- method: bubble_sort, cmp

--result:
 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
 内存消耗： 8 MB , 在所有 C++ 提交中击败了 23.75% 的用户
 通过测试用例： 81 / 81

-- analyse:
Time: O(nlogn)
Space: O(n)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
    static void bubble_sort(vector<int> &nums) {
        bool flag = true;
        for (int i = 0, n = nums.size() - 1; i < n && flag; ++i) {
            flag = false;
            for (int j = 0; j < n - i; ++j)
                if (nums[j] > nums[j + 1]) {
                    flag = true;
                    std::swap(nums[j], nums[j + 1]);
                }
        }
    }

public:
    // function start.
    static int heightChecker(vector<int> &heights) {
        vector<int> expected(heights);
        bubble_sort(expected);
        // std::sort(expected.begin(), expected.end());
        IC(expected);

        int ret = 0;
        for (int i = 0; i < heights.size(); i++)
            if (expected[i] != heights[i])
                ++ret;

        return ret;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    int ret = 3;
    IC(heights, ret);
    IC(solution->heightChecker(heights));


    // code end
    delete solution;
    return 0;
}
