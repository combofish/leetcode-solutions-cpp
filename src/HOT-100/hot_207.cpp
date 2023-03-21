/**
-- question:
-- method:
 - [*] 深度优先搜索
 - [ ] 广度优先搜索

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
        visited.resize(numCourses);
        for (const auto &item: prerequisites)
            edges[item.back()].emplace_back(item.front());

        for (int i = 0; i < numCourses && vaild; ++i)
            if (!visited[i]) traversal(i);

        return vaild;
    }

private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool vaild = true;

    void traversal(int u) {
        visited[u] = 1;
        for (const auto &v: edges[u]) {
            if (visited[v] == 0) {
                traversal(v);
                if (!vaild) return;
            } else if (visited[v] == 1) {
                vaild = false;
                return;
            }
        }
        visited[u] = 2;
    }

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
