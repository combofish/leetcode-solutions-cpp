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
#include <cctype>
#include <string>

class Solution {

    // function start.
public:
    string decodeString(string s) {
        stack<char> st;

        for (auto &c: s) {
            if (c != ']') st.push(c);
            else {
                // c == ']'

                string tmp = "";
                while (!st.empty() && st.top() != '[') {
                    tmp.push_back(st.top());
                    st.pop();
                }

                // pop '['
                st.pop();

                string numRec = "";
                while (!st.empty() && std::isdigit(st.top())) {
                    numRec.push_back(st.top());
                    st.pop();
                }
                std::reverse(numRec.begin(), numRec.end());

                auto n = std::stoi(numRec);

                string ret = repeat(tmp, n);
                for (auto &rc: ret)
                    st.push(rc);
            }
        }

        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }


        return res;
    }

private:
    std::string repeat(const std::string &s, unsigned int num) {
        std::string ret;
        ret.reserve(s.size() * num);
        while (num--)
            ret += s;

        return ret;
    }

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "3[a2[c]]";
    string ans = "accaccacc";
    IC(s, ans);

    IC(solution->decodeString(s));
    // code end

    return 0;
}
