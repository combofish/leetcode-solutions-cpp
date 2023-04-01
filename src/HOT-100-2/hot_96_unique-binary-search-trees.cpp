/**
-- question: 不同的二叉搜索树
-- method:
 - [-] 动态规划
 - [ ] 数学

--result:

-- analyse:
Time: O(n^2)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }

        IC(G);

        return G.back();


    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 3;
    int ans = 5;
    IC(n, ans);

    IC(solution->numTrees(n));

    // code end

    return 0;
}
