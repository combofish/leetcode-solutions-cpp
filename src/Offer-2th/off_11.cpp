/**
-- question: 旋转数组的最小数字
-- method:
 - [ ] min_element
 - [*] 二分查找
 - [ ] 找转折点

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
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int mid = (high + low) >> 1;

            if (numbers[mid] < numbers[high]) high = mid;
            else if (numbers[mid] > numbers[high])
                low = mid + 1;
            else
                high -= 1;
        }

        return numbers[low];
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
