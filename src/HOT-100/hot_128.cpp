/**
-- question: 最长连续序列
-- method:
 - [*] 哈希表

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int longestConsecutive(vector<int> &nums) {
        auto cacheSet = unordered_set<int>();
        for (const auto &item: nums) cacheSet.insert(item);

        IC(cacheSet);
        int longestStreak = 0;
        for (const auto &item: cacheSet) {
            if (cacheSet.count(item - 1)) continue;

            // count (item -1) == false;

            int currNum = item;
            int currStreak = 1;
            while (cacheSet.count(currNum + 1)) {
                currNum++;
                currStreak++;
            }

            if (currStreak > longestStreak) longestStreak = currStreak;
        }
        return longestStreak;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int rel = 4;
    IC(nums, rel);

    IC(solution->longestConsecutive(nums));
    // code end

    return 0;
}
