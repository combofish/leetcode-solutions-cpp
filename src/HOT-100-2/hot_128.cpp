/**
-- question: 最长连续序列
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int longestConsecutive(vector<int> &nums) {
        int n = nums.size();
        if (!n) return 0;

        unordered_set<int> uset;
        for (auto &n: nums) uset.insert(n);

        IC(uset);
        int ans = 0;

        for (auto &n: nums) {
            if (!uset.count(n)) continue;

            int lk = n - 1, rk = n + 1;
            uset.erase(n);

            while (uset.count(lk)) {
                uset.erase(lk);
                lk--;
            }

            while (uset.count(rk)) {
                uset.erase(rk);
                rk++;
            }

            IC(n, lk, rk);
            ans = std::max(ans, rk - lk - 1);
        }


        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int ans = 4;

    IC(nums, ans);

    IC(solution->longestConsecutive(nums));

    // code end

    return 0;
}
