/**
-- question:
-- method:
 - [*] Brian Kernighan 算法
 - [ ] 动态规划——最高有效位
 - [ ] 动态规划——最低有效位
 - [ ] 动态规划——最低设置位

--result:

-- analyse:
Time: O( nlogn )
Space: O( 1 )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> countBits(int n) {
        vector<int> record(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int cnt = 0;
            int tmp = i;
            while (tmp) {
                tmp &= (tmp - 1);
                cnt++;
            }
            record[i] = cnt;
        }

        return record;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 5;
    vector<int> rel = {0, 1, 1, 2, 1, 2};
    IC(n, rel);

    IC(solution->countBits(n));
    // code end

    return 0;
}
