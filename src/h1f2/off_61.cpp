/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    bool isStraight(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());

        int zero_cnt = 0;
        int gap_cnt = 0;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                ++zero_cnt;
            } else {
                if (i > 0 && nums[i - 1] != 0) {
                    int gap = nums[i] - nums[i - 1];

                    IC(zero_cnt, gap_cnt, gap);
                    if (gap > 1) {
                        gap_cnt += gap - 1;
                    }
                    if (gap == 0) {
                        return false;
                    }
                }
            }
        }

        IC(zero_cnt, gap_cnt);

        return zero_cnt >= gap_cnt;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start


    vector<int> nums = {0, 0, 1, 2, 5};

    bool ans = true;

    IC(nums, ans);
    IC(solution->isStraight(nums));


    // code end

    return 0;
}