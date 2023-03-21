/**
-- question: 字符串解码
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    string decodeString(string s) {
        stack<char> st;

        for (const auto &item: s) {
            if (item == ']') {
                string tmp;
                while (st.top() != '[') {
                    tmp += st.top();
                    st.pop();
                }
                std::reverse(tmp.begin(), tmp.end());

                IC(tmp);
                st.pop(); // pop '['

                string intStr;
                while (!st.empty() && std::isdigit(st.top())) {
                    intStr += st.top();
                    st.pop();
                }
                std::reverse(intStr.begin(), intStr.end());
                int n = std::stoi(intStr);
                while (n--) {
                    for (const auto &c: tmp)
                        st.push(c);
                }


            } else {
                st.push(item);
            }

            outStack(st);
        }


        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        std::reverse(result.begin(), result.end());
        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "3[a2[c]]";
    string rel = "accaccacc";

    IC(s, rel);
    IC(solution->decodeString(s) == rel);

    // code end

    return 0;
}


