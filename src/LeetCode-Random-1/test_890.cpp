/**
-- method: umap, uset
 每个字母映射到另一个字母，没有两个字母映射到同一个字母。

--result:
执行用时： 4 ms , 在所有 C++ 提交中击败了 66.05% 的用户
内存消耗： 8.4 MB , 在所有 C++ 提交中击败了 26.54% 的用户
通过测试用例： 47 / 47

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
    inline bool match(const string &word, const string &pattern) {
        unordered_map<char, char> umap;
        unordered_set<char> uset;

        for (int i = 0, n = pattern.size(); i < n; ++i) {
            char pc = pattern[i], wc = word[i];
            if (!umap.count(pc)) {
                if (!uset.count(wc)) {
                    umap[pc] = wc;
                    uset.insert(wc);
                } else {
                    return false;
                }
            } else {
                if (wc != umap[pc])
                    return false;
            }
        }

        return true;
    }

public:
    // function start.
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> ret;
        for (const auto &word: words)
            if (match(word, pattern))
                ret.emplace_back(word);

        return ret;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";
    IC(words, pattern);
    vector<string> ret = {"mee", "aqq"};
    IC(solution->findAndReplacePattern(words, pattern));
    IC(ret);
    // code end

    vector<string> words2 = {"ef", "fq", "ao", "at", "lx"};
    string patten2 = "ya";
    vector<string> ret2 = {"ef", "fq", "ao", "at", "lx"};
    IC(words2, patten2, ret2);
    IC(solution->findAndReplacePattern(words2, patten2));

    delete solution;
    return 0;
}
