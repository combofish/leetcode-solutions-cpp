/**
-- question: 除法求值
-- method:
 - []

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
    calcEquation(vector <vector<string>> &equations, vector<double> &values, vector <vector<string>> &queries) {



    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector <vector<string >> equations = {{"a", "b"},
                                          {"b", "c"},
                                          {"bc", "cd"}},
            queries = {{"a", "c"},
                       {"c", "b"},
                       {"bc", "cd"},
                       {"cd", "bc"}};

    vector<double> values = {1.5, 2.5, 5.0}, ans = {3.75000, 0.40000, 5.00000, 0.20000};

    IC(equations, queries, values, ans);

    IC(solution->calcEquation(equations, values, queries));

    // code end

    return 0;
}


