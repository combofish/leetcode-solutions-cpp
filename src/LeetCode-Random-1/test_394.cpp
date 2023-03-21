/**
-- method: 栈操作

--result:
执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
内存消耗： 6.6 MB , 在所有 C++ 提交中击败了 11.60% 的用户
通过测试用例： 34 / 34

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <string>

class Solution {
    string getDigits(string &s, std::size_t &ptr) {
        string ret = "";
        while (std::isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        IC(ret);
        return ret;
    }

    string getString(vector<string> &v) {
        string ret;
        IC(v);
        for (const auto &s: v)
            ret += s;
        IC(ret);
        return ret;
    }

public:
    // function start.
    string decodeString(string s) {
        vector<string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            IC(ptr, cur);

            if (std::isdigit(cur)) {
                string digits = getDigits(s, ptr);
                IC(digits);
                stk.push_back(digits);

            } else if (std::isalpha(cur) || cur == '[') {
                IC(string(1, s[ptr]));
                stk.push_back(string(1, s[ptr++]));
            } else {
                ++ptr;
                vector<string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                IC(sub, stk);
                std::reverse(sub.begin(), sub.end());
                stk.pop_back();
                IC(stk);

                int repTime = std::stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);
                while (repTime--)
                    t += o;
                stk.push_back(t);
            }
            IC(stk);
            out_line();
        }
        return getString(stk);
    }
    // function end.
};

int main() {

    Solution *solution = new Solution();

    // code start
    string s = "1[a2[c]]";
    IC(s);
    IC(solution->decodeString(s) == "accaccacc");

    // code end

    delete solution;
    return 0;
}
