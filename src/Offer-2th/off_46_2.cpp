/**
-- question: 把数字翻译成字符串
-- method:
 - [ ] backtracking
 - [*] dp
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
        if (!num) return 1;
        auto record = vector<int>();
        while (num) {
            record.emplace_back(num % 10);
            num /= 10;
        }
        std::reverse(record.begin(), record.end());

        int n = record.size();
        auto dp = vector<int>(n + 1, 0);
        dp.front() = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (i > 1 && record[i - 2]) {
                auto tmp = record[i - 2] * 10 + record[i - 1];
                if (tmp > 9 && tmp < 26) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
            }
        }

        IC(dp);
        return dp.back();
    }

private:
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
