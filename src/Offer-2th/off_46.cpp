/**
-- question: 把数字翻译成字符串
-- method:
 - [*] backtracking
 - [ ] dp
 - [ ] recursive

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
    int translateNum(int num) {
        auto record = vector<int>();
        while (num) {
            record.emplace_back(num % 10);
            num /= 10;
        }
        std::reverse(record.begin(), record.end());
        IC(record);

        backtracking(record, 0);
        return result;
    }

private:
    int result;
    void backtracking(const vector<int> &nums, int idx) {
        IC(nums, idx);

        if (idx >= nums.size()) {
            ++result;
            return;
        }

        backtracking(nums, idx + 1);

        if ((nums[idx] != 0) && idx + 1 < nums.size()) {
            auto two = nums[idx] * 10 + nums[idx + 1];
            if (two >= 10 && two <= 25) {
                backtracking(nums, idx + 2);
            }
        }
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 12258;
    int rel = 5;

    IC(n, rel);
    IC(solution->translateNum(n) == rel);
    // code end

    return 0;
}
