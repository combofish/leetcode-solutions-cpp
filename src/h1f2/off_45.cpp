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
    int jump(vector<int> &nums) {

        int n = nums.size();
        int cnt = 1;
        // int rk = 0;
        int i = 0;

        auto farest = i + nums[i];
        auto start_i = i;

        while (i < n) {
            ++cnt;

            int cur_far = farest;
            for (i = start_i; i <= cur_far; i++) {
                if (i + nums[i] > farest) {
                    farest = i + nums[i];
                    start_i = i;
                }
                // if(farest >= n-1) return cnt;
            }

            IC(cnt, cur_far, farest);

            if (farest >= n - 1) return cnt;
            i = start_i;
        }

        return -1;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 3, 1, 1, 4};
    IC(nums);
    IC(solution->jump(nums));
    // code end

    return 0;
}