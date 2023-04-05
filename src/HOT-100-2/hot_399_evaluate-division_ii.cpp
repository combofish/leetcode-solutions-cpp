/**
-- question: 除法求值
-- method:
 - [ ] 并查集
 - [-] 广度优先搜索

--result:

-- analyse:
Time: O( （N+Q)logA )
Space: O( A )
 */

#include "../combofish_utils.hpp"
#include <algorithm>


class Solution {

    // function start.
public:

    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        int id = 0;
        unordered_map<string, int> ump;
        int esz = equations.size();

        for (const auto &item: equations) {
            if (!ump.count(item.front())) ump[item.front()] = id++;
            if (!ump.count(item.back())) ump[item.back()] = id++;
        }

        IC(esz);
        IC(ump);

        vector<vector<pair<int, double>>> edges(id);
        IC(edges);

        for (int i = 0; i < esz; i++) {
            auto va = ump[equations[i].front()];
            auto vb = ump[equations[i].back()];

            IC(i, va, vb, values[i]);

            edges[va].emplace_back(vb, values[i]);
            edges[vb].emplace_back(va, 1.0 / values[i]);
        }

        IC(1);
        IC(edges);

        vector<double> ans;
        for (const auto &q: queries) {
            double result = -1.0;

            auto va = q.front();
            auto vb = q.back();
            if (ump.count(va) && ump.count(vb)) {
                auto ia = ump[va], ib = ump[vb];
                if (ia == ib) result = 1.0;
                else {
                    queue<int> points;
                    points.push(ia);
                    vector<double> ratios(id, -1.0);
                    ratios[ia] = 1.0;

                    IC(ia, ib, ratios);

                    while (!points.empty() && ratios[ib] < 0) {
                        auto x = points.front();
                        points.pop();

                        for (const auto &item: edges[x]) {
                            auto y = item.first;
                            auto val = item.second;

                            if (ratios[y] < 0) {
                                ratios[y] = ratios[x] * val;
                                points.push(y);
                            }
                        }

                        IC(x, ratios);
                    }

                    result = ratios[ib];
                }
            }
            ans.emplace_back(result);
            IC(ans);
        }

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

//    IC("ans");

    // code end

    return 0;
}


