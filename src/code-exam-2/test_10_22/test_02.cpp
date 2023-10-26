
#include <algorithm>
#include <cctype>
#include <icecream.hpp>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void out_st(stack<char> st) {
    string ans;
    while (!st.empty()) {
        ans += (st.top());
        st.pop();
    }

    std::reverse(ans.begin(), ans.end());
    IC(ans);
}

int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }

    string str;
    // cin>>str;
    str = "2(a3(b))2(cd)e2(f)";

    int n = str.size();
    stack<char> st;

    for (auto &c: str) {
        if (c == ')') {
            string tmp;
            while (!st.empty() && st.top() != '(') {
                tmp += st.top();
                st.pop();
            }
            std::reverse(tmp.begin(), tmp.end());
            st.pop();// pop '('

            string cnt_string;
            while (!st.empty() && std::isdigit(st.top())) {
                cnt_string += st.top();
                st.pop();
            }

            std::reverse(cnt_string.begin(), cnt_string.end());
            int cnt = std::stoi(cnt_string);

            for (int i = 0; i < cnt; ++i) {
                for (auto &per_c: tmp) {
                    st.push(per_c);
                }
            }


        } else {
            st.push(c);
        }
    }

    string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    std::reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")