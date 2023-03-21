/**
-- question: 旋转数组的最小数字
-- method:
 - [ ] min_element
 - [ ] 二分查找
 - [*] 找转折点

--result:

-- analyse:
Time: O(logn)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int minArray(vector<int> &numbers) {
        int n = numbers.size();
        if (n == 1) return numbers.front();

        for (int i = 1; i < n; i++) {
            if (numbers[i] < numbers[i - 1]) return numbers[i];
        }
        return numbers.front();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> numbers = {3, 4, 5, 1, 2};
    int rel = 1;
    IC(numbers, rel);

    IC(solution->minArray(numbers) == rel);
    // code end

    return 0;
}
