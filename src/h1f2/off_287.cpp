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
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;

        while (l <= r) {
            auto mid = ((r - l) >> 1) + l;
            int cnt = 0;
            for (auto &num: nums) {
                if (num <= mid) ++cnt;
            }

            IC(nums, l, r, mid, cnt);
            if (cnt <= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
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

    vector<int> nums = {1, 2, 3, 3, 4, 5, 6};
    IC(nums);

    IC(solution->findDuplicate(nums));
    // code end

    return 0;
}