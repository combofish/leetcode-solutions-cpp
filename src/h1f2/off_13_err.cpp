/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    // err by: 所选的格子不一定可达
    int movingCount(int m, int n, int k) {
        int ans = 0;
        int i = 0;
        while (i < m) {
            int j = n - 1;
            int i_n = sum_bit(i);
            while (j >= 0 && (i_n + sum_bit(j)) > k) {
                j--;
            }

            if (j >= 0) {
                cout << "(" << i << "," << j << ") ";
                ans += (j + 1);
            }
            i++;
            cout << endl;
        }

        return ans;
    }

private:
    int sum_bit(int n) {
        int ans = 0;
        for (auto &c: std::to_string(n))
            ans += (c - '0');

        return ans;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int m = 14, n = 14, k = 5;
    int ans = 21;


    IC(m, n, k, ans);
    IC(solution->movingCount(m, n, k));
    // code end

    return 0;
}