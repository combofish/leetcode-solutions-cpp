/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
private:

    // function start.
public:

    int lastStoneWeightII(vector<int> &stones) {
        int stonesSum = std::accumulate(stones.begin(), stones.end(), 0);
        int halfSum = stonesSum / 2;
        vector<int> dp(1501, 0);
        for (int stone : stones)
            for (int j = halfSum; j >= stone; j--)
                dp[j] = std::max(dp[j], dp[j - stone] + stone);


        return stonesSum - dp[halfSum] * 2;

    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    int rel = 1;
    IC(stones, rel);
    IC(solution->lastStoneWeightII(stones) == rel);

    // code end

    delete solution;
    return 0;
}


