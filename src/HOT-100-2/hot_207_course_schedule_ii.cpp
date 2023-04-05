/**
-- question: 课程表
-- method:
 - [ ] 深度优先搜索
 - [-] 广度优先搜索 (入度)

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
        for (const auto &item: prerequisites) {
            edges[item.back()].emplace_back(item.front());
            ++vis[item.front()];
        }

        queue<int> qu;
        for (int i = 0; i < numCourses; ++i) if (vis[i] == 0) qu.push(i);

        IC(vis, edges);
        out_qu(qu);

        int visited = 0;
        while (!qu.empty()) {
            ++visited;
            auto u = qu.front();
            qu.pop();

            for (auto v: edges[u]) {
                --vis[v];
                if (vis[v] == 0) {
                    qu.push(v);
                }
            }
        }

        return visited == numCourses;

    }

private:

    vector<int> vis;
    vector<vector<int>> edges;
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
