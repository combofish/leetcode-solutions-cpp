/**
-- question: 寻找重复数
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
    int findDuplicate(vector<int> &nums) {
        unordered_set<int> uset;
        for (const auto &item: nums)
            if (uset.find(item) != uset.end())
                return item;
            else
                uset.insert(item);

        return -1;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 3, 4, 2, 2};
    int rel = 2;

    IC(nums, rel);
    IC(solution->findDuplicate(nums) == rel);
    // code end

    return 0;
}


