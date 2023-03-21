/**
-- question: 除法求值
-- method:
 - [ ] 并查集
 - [*] 广度优先搜索
 - [ ] Floyd 算法

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>


class Solution {

    // function start.
public:

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {

        int nVars = 0;
        unordered_map<string, int> cache;
        for (const auto &item: equations) {
            if (!cache.count(item.front())) cache[item.front()] = nVars++;
            if (!cache.count(item.back())) cache[item.back()] = nVars++;
        }


        int n = equations.size();


        // 对于每个点，存储其直接连接到的所有点及对应的权值
        vector<vector<pair<int, double>>> edges(nVars);
        for (int i = 0; i < n; i++) {
            int id1 = cache[equations[i].front()];
            int id2 = cache[equations[i].back()];

            edges[id1].push_back({id2, values[i]});
            edges[id2].push_back({id1, 1.0 / values[i]});
        }

        IC(cache);
        IC(nVars);
        IC(edges);

        vector<double> result;
        for (const auto &item: queries) {
            double ret = -1.0;
            if (cache.count(item.front()) && cache.count(item.back())) {
                int id1 = cache[item.front()];
                int id2 = cache[item.back()];
                if (id1 == id2) ret = 1.0;
                else {
                    queue<int> points;
                    points.push(id1);
                    vector<double> ratios(nVars, -1.0);
                    ratios[id1] = 1.0;

                    while (!points.empty() && ratios[id2] < 0) {
                        int x = points.front();
                        points.pop();
                        for (const auto &edge: edges[x]) {
                            if (ratios[edge.first] < 0) {
                                ratios[edge.first] = ratios[x] * edge.second;
                                points.push(edge.first);
                            }
                        }
                    }

                    IC(ratios);

                    ret = ratios[id2];
                }
            }
            result.emplace_back(ret);

            IC(result);
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


