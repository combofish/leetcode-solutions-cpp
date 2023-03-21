/**
-- question: 至少有 1 位重复的数字
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <string>

class Solution {

    // function start.
public:
    int numDupDigitsAtMostN(int n) {

        int ans = 0;
        do {
            ans += isDupN(n--);
        } while (n >= 1);

        return ans;
    }


private:
    int isDupN(int n) {
        IC(n);
        auto n_str = std::to_string(n);
        unordered_set<int> uset;

        for (auto &c: n_str) {
            if (uset.count(c)) return 1;
            else
                uset.insert(c);
        }


        return 0;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 100;
    int res = 10;
    IC(n, res);
    IC(solution->numDupDigitsAtMostN(n));

    // code end

    return 0;
}
