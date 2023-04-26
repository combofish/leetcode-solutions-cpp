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
    const int dirs[2][2] = {{1, 0},
                            {0, 1}};

    struct hashFunction {
        size_t operator()(const pair<int, int> &x) const {
            return std::hash<int>()(x.first) ^ std::hash<int>()(x.second);
        }
    };

    // err by: 所选的格子不一定可达
    int movingCount(int m, int n, int k) {
        int i = 0, j = 0;
        if (i + j > k) return 0;
        int ans = 1;
        unordered_set<pair<int, int>, hashFunction> uet, tmp_uet;
        uet.insert({i, j});

        while (!uet.empty()) {
            tmp_uet.clear();

            for (auto &item: uet) {
                for (auto &dir: dirs) {
                    auto ni = item.first + dir[0];
                    auto nj = item.second + dir[1];

                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && sum_bit_i_j(ni, nj) <= k) {
                        tmp_uet.insert({ni, nj});
                    }
                }
            }
            ans += tmp_uet.size();
            uet = tmp_uet;
        }

        return ans;

    }

private:
    inline int sum_bit(int n) {
        int ans = 0;
        for (auto &c: std::to_string(n)) {
            ans += (c - '0');
        }
        return ans;
    }

    inline int sum_bit_i_j(int a, int b) {
        return sum_bit(a) + sum_bit(b);
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