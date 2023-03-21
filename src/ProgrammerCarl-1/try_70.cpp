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
    int climbStairs(int n) {
        if(n<=2) return n;
        int n_1 = 1, n_2 = 2;
        for(int i = 3; i<=n; i++){
            int tmp = n_1 + n_2;
            n_2 = n_1;
            n_1 = tmp;
        }
        return n_1;
    }

    int climbStairs_2(int n) {
        if(n<=2) return n;
        int dp[2] = {1,2};
        for(int i = 3; i<=n;i++){
            int tmp = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = tmp;
        }

        return dp[1];
    }

  // function end.
};

int main() {

  auto solution = new Solution();

  // code start
    int n =3;
    int rel = 3;
    IC(n, rel);
    IC(solution->climbStairs(n));
    IC(solution->climbStairs_2(n));
  // code end

  delete solution;
  return 0;
}


