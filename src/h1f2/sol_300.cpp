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
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        vector<int> rec(n);
        rec.front() = nums.front();
        int len = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > rec[len]) {
                rec[++len] = nums[i];
            } else {
                auto idx = len;
                while (idx >= 0 && nums[i] <= rec[idx]) {
                    --idx;
                }
                rec[++idx] = nums[i];
            }
            IC(rec, len);
        }

        return len + 1;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int ans = 4;
    IC(nums, ans);

    IC(solution->lengthOfLIS(nums));

    string  tmp = "0";
    IC(std::stoi(tmp));
    // code end

    return 0;
}