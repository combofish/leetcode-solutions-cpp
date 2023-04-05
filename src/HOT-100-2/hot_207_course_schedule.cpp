/**
-- question: 课程表
-- method:
 - [-] 深度优先搜索
 - [ ] 广度优先搜索

--result:

-- analyse:
Time: O( n + m)
Space: O( n + m )
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        vis.resize(numCourses);
        valid = true;

        for (const auto &item: prerequisites) edges[item.back()].emplace_back(item.front());

        for (int i = 0; i < numCourses && valid; ++i)
            if (!vis[i]) dfs(i);

        IC(vis);
        IC(edges);

        return valid;
    }

private:
    vector<int> vis;
    vector<vector<int>> edges;
    bool valid;

    void dfs(int u) {
        vis[u] = 1;
        for (int v: edges[u]) {
            if (vis[v] == 0) {
                dfs(v);
                if (!valid) return;
            } else if (vis[v] == 1) {
                valid = false;
                return;
            }
        }
        vis[u] = 2;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0},
                                         {0, 1}};
    bool ans = false;

    IC(numCourses, prerequisites, ans);
    IC(solution->canFinish(numCourses, prerequisites));

    // code end

    return 0;
}
