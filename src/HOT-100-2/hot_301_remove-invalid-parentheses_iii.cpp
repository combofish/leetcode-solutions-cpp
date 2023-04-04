/**
-- question: 删除无效的括号
-- method:
 - [ ] 回溯 + 剪枝
 - [ ] 广度优先搜索
 - [-] 枚举状态子集

--result:

-- analyse:
Time: O( nxn^2 )
Space: O( nx C(_n,m) )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    vector<string> removeInvalidParentheses(string s) {
        int lrm = 0, rrm = 0;
        vector<int> left, right;
        vector<string> ans;
        unordered_set<string> cnt;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.push_back(i);
                ++lrm;
            } else if (s[i] == ')') {
                right.push_back(i);
                if (lrm > 0) --lrm;
                else ++rrm;
            }
        }
        IC(left, right);
        IC(lrm, rrm);

        int m = left.size(), n = right.size();
        vector<int> maskArr1, maskArr2;

        IC(1<<m);

        for (int i = 0; i < (1 << m); i++) {
            if (__builtin_popcount(i) != lrm) continue;
            maskArr1.push_back(i);
        }

        for (int i = 0; i < (1 << n); i++) {
            if (__builtin_popcount(i) != rrm) continue;
            maskArr2.push_back(i);
        }

        IC(m,n);
        IC(maskArr1, maskArr2);

        for (const auto &mask1: maskArr1) {
            for (const auto &mask2: maskArr2) {
                if (checkValid(s, mask1, left, mask2, right))
                    cnt.insert(recoverStr(s, mask1, left, mask2, right));
            }
        }

        for (const auto &v: cnt) {
            ans.emplace_back(v);
        }

        return ans;
    }

private:
    bool checkValid(const string &str, int l_mask, vector<int> &left, int r_mask, vector<int> &right) {
        IC(left, right);
        IC(l_mask, r_mask);

        int pos1 = 0, pos2 = 0, cnt = 0;

        for (int i = 0; i < str.size(); i++) {
            if (pos1 < left.size() && i == left[pos1]) {
                if (!(l_mask & (1 << pos1))) {
                    cnt++;
                }
                pos1++;
            } else if (pos2 < right.size() && i == right[pos2]) {
                if (!(r_mask & (1 << pos2))) {
                    cnt--;
                    if (cnt < 0) {
                        return false;
                    }
                }
                pos2++;
            }
        }
        return cnt == 0;
    }

    string recoverStr(const string &str, int l_mask, vector<int> &left, int r_mask, vector<int> &right) {
        string ans;
        int pos1 = 0, pos2 = 0;

        for (int i = 0; i < str.size(); i++) {
            if (pos1 < left.size() && i == left[pos1]) {
                if (!(l_mask & (1 << pos1))) {
                    ans.push_back(str[i]);
                }
                pos1++;
            } else if (pos2 < right.size() && i == right[pos2]) {
                if (!(r_mask & (1 << pos2))) {
                    ans.push_back(str[i]);
                }
                pos2++;
            } else {
                ans.push_back(str[i]);
            }
        }

        return ans;
    }


    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "(a)())()";

    vector<string> ans = {"(a())()", "(a)()()"};

    IC(s, ans);

    IC(solution->removeInvalidParentheses(s));

    // code end

    return 0;
}
