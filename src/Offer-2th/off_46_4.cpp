/**
-- question: 把数字翻译成字符串
-- method:
 - [ ] backtracking
 - [ ] dp
 - [*] recursive
 - [ ] str + dp 优化

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
    int translateNum(int num) {
        if (!num) return 1;

        auto str = std::to_string(num);
        std::pair<int, int> rec(1,1);

        rec.first = 1;
        rec.second = 1;

        int n = str.size();
        for (int i = 1; i < n; i++) {
            auto tmp = rec.second;

            auto sub = str.substr(i - 1, 2);
            if (sub >= "10" && sub <= "25") {
                tmp += rec.first;
            }

            rec.first = rec.second;
            rec.second = tmp;
            IC(sub, rec);
        }

        return rec.second;
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
