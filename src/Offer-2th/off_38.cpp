/**
-- question:
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
    vector<string> permutation(string s) {

        // 没去重复

        results.clear();

        auto used = vector<bool>(s.size(), false);
        backtracking(used, "", s);
        return results;
    }


private:
    vector<string> results;

    void backtracking(vector<bool> &used, string path, const string &s) {
        if (path.size() == s.size()) {
            results.emplace_back(path);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            backtracking(used, path + s[i], s);
            used[i] = false;
        }
    }


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "abc";
    auto rec = {"abc", "acb", "bac", "bca", "cab", "cba"};


    IC(s, rec);
    IC(solution->permutation(s));
    // code end

    return 0;
}
