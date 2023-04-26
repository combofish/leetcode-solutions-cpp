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

    // err by: 所选的格子不一定可达
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        int ans = 1;
        queue<pair<int, int>> qu;
        qu.push({0, 0});

        while (!qu.empty()) {
            auto p = qu.front();
            qu.pop();
            for (auto &item: dirs) {
                auto ni = p.first + item[0];
                auto nj = p.second + item[1];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[ni][nj] && get(ni) + get(nj) <= k) {
                    ++ans;
                    vis[ni][nj] = true;
                    qu.push({ni, nj});
                }
            }
        }
        return ans;
    }

private:
    inline int get(int n) {
        int ans = 0;
        while (n > 0) {
            ans += n % 10;
            n /= 10;
        }
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