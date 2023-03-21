/**
-- question: 汉明距离
-- method:
 - [ ] 内置位计数功能
 - [*] 移位实现位计数
 - [ ] Brian Kernighan 算法

--result:

-- analyse:
Time: O(log C)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int result = 0;
        while (tmp) {
            result += tmp & 1;
            tmp >>= 1;
        }
        return result;

    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int x = 1, y = 4, rel = 2;
    IC(x, y, rel);

    IC(solution->hammingDistance(x, y) == rel);

    // code end

    return 0;
}


