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
        vector<string> ret;
        sort(s.begin(), s.end());
        do {
            ret.emplace_back(s);
        } while (nextPermutation(s));

        return ret;
    }

private:
    bool nextPermutation(string &s) {
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) i--;

        if (i < 0) return false;
        int j = s.size() - 1;
        while (j >= 0 && s[i] >= s[j]) j--;

        swap(s[i], s[j]);
        std::reverse(s.begin() + i + 1, s.end());

        IC(s);
        return true;
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

    auto t_s = "ab";
    IC(solution->permutation(t_s));

    return 0;
}
