/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
private:

    // function start.
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        auto count = [&m, &n](const string &str) {
            int tmp[2] = {0};
            for (auto c: str)
                tmp[c - '0']++;

            if (tmp[0] > m or tmp[1] > n) return false;
            return true;
        };

        int res = 0;
        for (auto str: strs)
            if (count(str)) res++;

        return res == strs.size() ? res - 1 : res;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3, rel = 4;
    IC(strs, m, n, rel);

    IC(solution->findMaxForm(strs, m, n) == rel);


    vector<string> strs_2 = {"10", "0001", "111001", "1", "0"};
    int m_2 = 4;
    int n_2 = 3;
    int rel_2 = 3;
    IC(strs_2, m_2, n_2, rel_2);

    IC(solution->findMaxForm(strs_2, m_2, n_2) == rel_2);

    // code end

    delete solution;
    return 0;
}


