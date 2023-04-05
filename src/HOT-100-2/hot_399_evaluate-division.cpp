/**
-- question: 除法求值
-- method:
 - [-] 并查集
 - [ ] 广度优先搜索

--result:

-- analyse:
Time: O( （N+Q)logA)
Space: O( A )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class UnionFind {
public:
    UnionFind(int n) : parent(n), weight(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            weight[i] = 1.0;
        }
    }

    void f_union(int x, int y, double value) {
        auto rootX = find(x);
        auto rootY = find(y);
        if (rootX == rootY) return;

        parent[rootX] = rootY;
        weight[rootX] = weight[y] * value / weight[x];
    }


    double isConnected(int x, int y) {
        auto rootX = find(x);
        auto rootY = find(y);
        if (rootX == rootY) return weight[x] / weight[y];
        else return -1.0;
    }

    void out_member() {
        IC(this->parent, this->weight);
    }

private:
    vector<int> parent;
    vector<double> weight;

    /**
     * 路径压缩
     * @param x
     * @return
     */
    int find(int x) {
        if (x != parent[x]) {
            auto origin = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[origin];
        }
        return parent[x];
    }


};

class Solution {

    // function start.
public:

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        int esz = equations.size();

        // auto unionFind = new UnionFind(2 * esz);
        auto unionFind = std::make_shared<UnionFind>(2 * esz);
        unionFind->out_member();

        unordered_map<string, int> ump;
        int id = 0;
        for (int i = 0; i < esz; i++) {
            auto equation = equations[i];
            auto var1 = equation.front();
            auto var2 = equation.back();

            if (!ump.count(var1)) {
                ump[var1] = id;
                id++;
            }

            if (!ump.count(var2)) {
                ump[var2] = id;
                id++;
            }

            unionFind->f_union(ump[var1], ump[var2], values[i]);
            unionFind->out_member();
        }

        IC(ump);

        // 做查询
        int sz = queries.size();
        vector<double> ans(sz);

        for (int i = 0; i < sz; i++) {
            auto var1 = queries[i].front();
            auto var2 = queries[i].back();

            if (!ump.count(var1) || !ump.count(var2)) {
                ans[i] = -1.0;
            } else {
                ans[i] = unionFind->isConnected(ump[var1], ump[var2]);
            }
        }

        unionFind->out_member();
        // delete unionFind;
        return ans;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<string >> equations = {{"a",  "b"},
                                         {"b",  "c"},
                                         {"bc", "cd"}},
            queries = {{"a",  "c"},
                       {"c",  "b"},
                       {"bc", "cd"},
                       {"cd", "bc"}};

    vector<double> values = {1.5, 2.5, 5.0}, ans = {3.75000, 0.40000, 5.00000, 0.20000};

    IC(equations, queries, values, ans);

    IC(solution->calcEquation(equations, values, queries));

    // code end

    return 0;
}


