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
    inline int cnt(const string &word) {
        vector<int> rec(26);
        for (auto &c: word) {
            ++rec[c - 'a'];
        }

        for (auto &n: rec) {
            if (n != 0) return n;
        }
        return -1;
    }

    inline int idx(vector<int> &rec, int idx) {
        int ans = rec.size();
        int lk = 0, rk = ans - 1;
        while (lk <= rk) {
            auto mid = (lk + rk) >> 1;
            if (idx < rec[mid]) {
                ans = mid;
                rk = mid - 1;
            } else {
                lk = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        int qn = queries.size();
        int wn = words.size();

        vector<int> rec(wn);
        for (int i = 0; i < wn; ++i) {
            rec[i] = cnt(words[i]);
        }

        std::sort(rec.begin(), rec.end());
        IC(rec);

        vector<int> ans(qn);
        for (int i = 0; i < qn; ++i) {
            auto target = cnt(queries[i]);
            IC(target, idx(rec, target));

            ans[i] = wn - idx(rec, target);
        }

        return ans;
    }
    // function start.
public:

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<string> queries = {"bbb", "cc"}, words = {"a", "aa", "aaaa", "aaa"};
    vector<int> ans = {1, 2};

    IC(queries, words, ans);
    IC(solution->numSmallerByFrequency(queries, words));
    // code end

    return 0;
}