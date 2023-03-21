/**
-- question: 除法求值
-- method:
 - [*] 并查集
 - [ ] 广度优先搜索
 - [ ] Floyd 算法

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class UnionFind {
public:
    UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            parent.emplace_back(i);
            weight.emplace_back(1.0); // 权重初始化为1
        }
    }


    /**
     * 路径压缩: 在查询一个结点 a 的根结点同时，把结点 a 到根结点的沿途所有结点的父亲结点都指向根结点。
     * @param x
     * @return 根结点的 id
     */
    int find(int x) {
        testStr += "    > ";
        string debugStr = testStr + "find(" + std::to_string(x)+")";
        IC(debugStr);

        // 递归寻找根节点，更新该点到根的权重为该点父节点到根的权重
        if (x != parent[x]) {
            int origin = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[origin];
        }


        testOut();

        testStr.clear();
        return parent[x];
    }

    /**
     * 返回除法结果。如果两个值不存在则-1
     * @param x
     * @param y
     * @return
     */
    double isConnected(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        // 如果两个值有共同的根也就是可以计算，则算结果。否则不在同一个并查集，-1
        if (rootX == rootY) return weight[x] / weight[y];
        else return -1.0;
    }

    void makeUnion(int x, int y, double value) {
        IC(x, y, value);

        // 分别找到二者的根节点
        int rootX = find(x);
        int rootY = find(y);

        IC(rootX, rootY);

        if (rootY == rootX) return;  // 二者已经指向同一个根节点

        testOut();
        // 令分子指向分母的根节点，权重为分母到根的权重*分母除分子的值/分子到根的权重。一开始都是1
        parent[rootX] = rootY;
        weight[rootX] = weight[y] * value / weight[x];
        testOut();
    }

    void testOut() {
        IC(parent, weight);
        // IC(weight);
    }


private:
    vector<int> parent; // 存放父节点
    vector<double> weight; // 指向父节点的权值

    string testStr = "";
};

class Solution {

    // function start.
public:

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        int equationsSize = equations.size();
        UnionFind unionFind(2 * equationsSize);
        std::unordered_map<string, int> hashMap;
        int id = 0;
        for (int i = 0; i < equationsSize; ++i) {
            IC("_________", i);
            auto equation = equations[i];
            string var1 = equation.front();
            string var2 = equation.back();
            if (!hashMap.count(var1)) {
                hashMap[var1] = id;
                ++id;
            }

            if (!hashMap.count(var2)) {
                hashMap[var2] = id;
                ++id;
            }

            unionFind.makeUnion(hashMap[var1], hashMap[var2], values[i]);
        }

        unionFind.testOut();
        IC(hashMap);

        int queriesSize = queries.size();
        vector<double> result(queriesSize, -1.0);
        for (int i = 0; i < queriesSize; i++) {
            auto var1 = queries[i].front();
            auto var2 = queries[i].back();
            int id1, id2;
            if (hashMap.count(var1) && hashMap.count(var2)) {
                id1 = hashMap[var1];
                id2 = hashMap[var2];
                result[i] = unionFind.isConnected(id1, id2);
            }
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<string>> equations = {{"a", "b"},
                                        {"b", "c"}};
    vector<double> values = {2.0, 3.0};

    vector<vector<string>> queries = {{"a", "c"},
                                      {"b", "a"},
                                      {"a", "e"},
                                      {"a", "a"},
                                      {"x", "x"}};

    IC(equations, values, queries);

    IC(solution->calcEquation(equations, values, queries));

    // code end

    return 0;
}


