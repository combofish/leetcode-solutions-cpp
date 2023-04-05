/**
-- question: 下一个排列
-- method:
 - [ ] 两遍扫描

--result:

-- analyse:
Time: O(N)
Space: O(1)
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    void nextPermutation(vector<int> &nums) {
        // std::next_permutation(nums.begin(), nums.end());

        //int n = nums.size();
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;
        IC(i, nums[i]);

        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) --j;
            IC(j, nums[j]);

            swap(nums[i], nums[j]);
        }

        std::reverse(nums.begin() + i + 1, nums.end());


    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 5, 8, 4, 7, 6, 5, 3, 1}, ansN = {1, 5, 8, 5, 1, 3, 4, 6, 7};
    IC(nums);
    IC(ansN);

    solution->nextPermutation(nums);
    IC(nums);

    // code end

    return 0;
}
