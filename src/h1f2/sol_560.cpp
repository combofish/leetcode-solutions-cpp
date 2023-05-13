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
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();

        int lk = -1;
        int sum_n = 0;
        int cnt = 0;

        int i = 0;
        while (lk + 1 < n) {
            IC(sum_n);
            while (i < n && sum_n + nums[i] <= k) {
                sum_n += nums[i];
                i++;
            }
            IC(sum_n);

            if (sum_n == k) ++cnt;

            sum_n -= nums[++lk];
        }
        return cnt;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 1, 1};
    int k = 2;
    IC(nums);
    IC(solution->subarraySum(nums, k));

    // code end

    return 0;
}