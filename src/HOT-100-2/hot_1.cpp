/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O(N)
Space: O(N)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        auto rec = unordered_map<int, int>();
        for (int i = 0; i < nums.size(); i++) {
            auto j = target - nums[i];

            if (rec.count(nums[i])) {
                return {rec[nums[i]], i};
            } else {
                rec.insert({j, i});
            }


            IC(rec);
        }

        return {};
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start


    vector<int> nums = {2, 7, 11, 15};
    auto target = 9;
    IC(nums, target);

    auto result = {0, 1};
    IC(result);

    IC(solution->twoSum(nums, target));
    // code end

    return 0;
}
