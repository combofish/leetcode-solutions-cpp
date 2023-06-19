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

class Solution {
    inline bool isVowel(char &c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    // function start.
public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
        int n = queries.size();
        int wn = words.size();
        vector<int> ans(n), rec(wn, 0);

        for (int i = 0; i < wn; i++) {
            if (isVowel(words[i].front()) &&
                isVowel(words[i].back()))
                rec[i] = 1;
        }

        vector<int> prefix(wn + 1, 0);
        for (int i = 1; i <= wn; ++i) {
            prefix[i] = prefix[i - 1] + rec[i - 1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = prefix[queries[i].back() + 1] - prefix[queries[i].front()];
            // int cnt = 0;
            // auto sk = queries[i].front();
            // auto ek = queries[i].back();
            // for(int j = sk; j <= ek; ++j){
            //     cnt += rec[j];
            // }
            // ans[i] = cnt;
        }
        return ans;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2},
                                   {1, 4},
                                   {1, 1}};
    vector<int> ans = {2, 3, 0};
    IC(words, queries, ans);

    IC(solution->vowelStrings(words, queries));
    // code end

    return 0;
}