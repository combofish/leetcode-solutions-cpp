/**
-- method: 双指针

--result:
执行用时：12 ms, 在所有 C++ 提交中击败了92.25%的用户
内存消耗：17.7 MB, 在所有 C++ 提交中击败了32.36%的用户
通过测试用例：17 / 17

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    vector<int> exchange(vector<int> &nums) {
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            // while (i < j && nums[i] % 2 == 1) {
            while (nums[i] % 2 == 1) {
                i++;
            }
            IC(i, j);

            // 是偶数
            while (i < j && nums[j] % 2 == 0) {
                --j;
            }

            if (j > i) {
                std::swap(nums[i], nums[j]);
                --j;
            }
            i++;
        }

        return nums;
    }
    // function end.
};

int main() {

    Solution *solution = new Solution();
    vec_t res = {1, 2, 3, 4};
    IC(res);
    IC(solution->exchange(res));

    out_line();
    vec_t res2 = {2, 4, 6};
    IC(res2);
    IC(solution->exchange(res2));

    out_line();
    vec_t res3 = {1, 3, 5};
    IC(res3);
    IC(solution->exchange(res3));

    delete solution;

    // code start
    return 0;
}
