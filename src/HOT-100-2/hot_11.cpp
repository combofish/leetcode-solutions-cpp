/**
-- question:
-- method:
 - [*] 双指针

--result:

-- analyse:
Time: O(N)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int maxArea(vector<int> &height) {
        int lk = 0, rk = height.size() - 1;
        int ans = 0;

        while (lk < rk) {
            auto tmp = std::min(height[lk], height[rk]) * (rk - lk);
            if (tmp > ans) ans = tmp;

            if (height[lk] < height[rk]) {
                lk++;
            } else {
                rk--;
            }
        }

        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int res = 49;

    IC(nums, res);

    IC(solution->maxArea(nums));

    // code end

    return 0;
}
