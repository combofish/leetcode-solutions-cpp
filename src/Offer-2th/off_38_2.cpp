/**
-- question: 字符串的排列
-- method:
 - [*] 回溯
 - [ ] 下一个排列

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <string>

class Solution {

    // function start.
public:
    vector<string> permutation(string s) {

        results.clear();
        std::sort(s.begin(), s.end());

        int n = s.size();
        used.resize(n);

        string path = "";
        backtracking(path, 0, n, s);
        return results;
    }


private:
    vector<string> results;
    vector<bool> used;

    void backtracking(string &path, int i, int n, const string &s) {
        if (i == n) {
            results.emplace_back(path);
            return;
        }

        for (int j = 0; j < n; j++) {
            // 去重复
            if (used[j] || (j > 1 && !used[j - 1] && s[j - 1] == s[j])) continue;

            used[i] = true;
            path.push_back(s[j]);
            backtracking(path, i + 1, n, s);
            path.pop_back();
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
