/**
-- method: count_sort

--result:
 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
 内存消耗： 8 MB , 在所有 C++ 提交中击败了 26.79% 的用户
 通过测试用例： 81 / 81

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

public:
    // function start.
    static int heightChecker(vector<int> &heights) {
        int m = *std::max_element(heights.begin(), heights.end());
        vector<int> cnt(m + 1);
        for (const auto &h: heights)
            cnt[h]++;

        IC(cnt);

        int ret = 0, idx = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < cnt[i]; ++j) {

                if (heights[idx] != i)
                    ++ret;
                ++idx;
            }
        }

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
