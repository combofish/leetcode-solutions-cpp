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
    // vector<int> sortedSquares(vector<int> &nums) {
    //     int i = 0;
    //     int j = nums.size() - 1;

    //     vec_t res(nums.size(), 0);

    //     int n = nums.size() - 1;
    //     while (n >= 0 && i <= j) {
    //         int p1 = std::pow(nums[i], 2);
    //         int p2 = std::pow(nums[j], 2);
    //         if (p1 < p2) {
    //             res[n] = p2;
    //             j--;
    //         } else {
    //             res[n] = p1;
    //             i++;
    //         }

    //         n--;
    //     }

    //     return res;
    // }

    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> res(nums.size(), 0);

        for (int i = 0, j = nums.size() - 1, k = nums.size() - 1; i <= j;) {
            int p1 = std::pow(nums[i], 2);
            int p2 = std::pow(nums[j], 2);

            IC(i, j, k, p1, p2);

            if (p1 < p2) {
                res[k--] = p2;
                j--;
            } else {
                res[k--] = p1;
                i++;
            }
        }

        return res;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vec_t nums = {-4, -1, 0, 3, 10};
    IC(nums);
    IC(solution->sortedSquares(nums));

    // code end

    delete solution;
    return 0;
}
