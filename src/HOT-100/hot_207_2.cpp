/**
-- question:
-- method:
 - [ ] 深度优先搜索
 - [*] 广度优先搜索

--result:

-- analyse:
Time: O(n+m)
Space: O(n+m)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <cmath>

class Solution {

    // function start.
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto &item: prerequisites) {
            edges[item.back()].emplace_back(item.front());
            ++indeg[item.front()];
        }
        IC(edges, indeg);

        queue<int> qu;
        for (int i = 0; i < numCourses; i++) {
            if (!indeg[i]) qu.push(i);
        }
        IC(qu);

        int visited = 0;
        while (!qu.empty()) {
            ++visited;
            int u = qu.front();
            qu.pop();
            for (const auto &v: edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) qu.push(v);
            }
        }

        return visited == numCourses;
    }

private:
    vector<vector<int>> edges;
    vector<int> indeg;// 入度

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0},
                                         {0, 1}};
    bool rel = false;

    IC(solution->canFinish(numCourses, prerequisites) == rel);
    // code end

    return 0;
}
