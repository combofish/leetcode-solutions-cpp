/**
-- question: 连续子数组的最大和
-- method:
 - [ ] dp
 - [*] 滚动数组

--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <climits>
#include <icecream.hpp>

class Solution {

    // function start.
public:
    int maxSubArray(vector<int> &nums) {

        int result = nums.front();
        int max_rec = nums.front();

        for (int i = 1; i < nums.size(); i++) {
            auto tmp = std::max(max_rec + nums[i], nums[i]);
            if (tmp > result) result = tmp;
            max_rec = tmp;
            IC(tmp, result, max_rec);
        }

        return result;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int rel = 6;

    IC(nums, rel);
    IC(solution->maxSubArray(nums) == rel);
    // code end


//    IC(treenode_tools::a);
//    icecream::f_("UU");

//    auto dd = std::make_shared<person>();
//    dd->out();

    outStack(stack<int>());
    return 0;
}
