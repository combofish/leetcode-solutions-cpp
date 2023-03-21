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
    int findContentChildren(vector<int> &g, vector<int> &s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

//        int result = 0;
//        for (int i = 0, j = 0; i < g.size() && j < s.size();) {
//            if (s[j] >= g[i]) {
//                i++;
//                j++;
//                result++;
//            } else {
//                j++;
//            }
//        }
//
//        return result;
        int idx = 0;
        for (int j : s)
            if (idx < g.size() && j >= g[idx])
                idx++;

        return idx;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    int rel = 1;

    IC(g, s, rel);
    IC(solution->findContentChildren(g, s));

    // code end

    delete solution;
    return 0;
}


