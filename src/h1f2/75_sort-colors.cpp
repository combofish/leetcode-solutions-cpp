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
    void sortColors(vector<int> &nums) {
        int lk = 0;
        int rk = nums.size() - 1;

        for(int i = 0; i<=rk; i++){
            if(nums[i] == 0) std::swap(nums[i], nums[lk++]);
            else if(nums[i] == 2) std::swap(nums[i], nums[rk--]);

            IC(nums, i, lk, rk);

            //
            string err = "交换过来的数可能是2，没有处理这种情况";
            IC(err);

//            int a = -100;
//            IC(std::to_string(a));
        }

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> ans = {0, 0, 1, 1, 2, 2};

    nums = {1,2,0};
    IC(nums, ans);

    solution->sortColors(nums);

    IC(nums);
    // code end

    return 0;
}