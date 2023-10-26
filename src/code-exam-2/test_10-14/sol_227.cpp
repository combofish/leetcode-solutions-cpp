#include <icecream.hpp>
#include <stack>
#include <string>
#include <vector>

using namespace std;
class Solution {
    void out_st(stack<string> st) {
        while (!st.empty()) {
            IC(st.top());
            st.pop();
        }
    }

public:
    int calculate(string s) {

        string tmp;
        stack<string> st;


        for (auto &c: s) {
            if (c == ' ') {
                if (!tmp.empty()) {
                    st.push(tmp);
                    tmp.clear();
                }
            } else if (c == '+' || c == '-' || c == '*' || '/') {
                if (!tmp.empty()) {
                    st.push(tmp);
                    tmp.clear();
                }

                tmp = c;
            } else {
                tmp += c;
            }
        }

        if (!tmp.empty()) {
            st.push(tmp);
            tmp.clear();
        }

        // IC(st);
        out_st(st);

        stack<string> st2;

        while(!st.empty()){
            auto item = st.top(); st.pop();
            
            if(item == "*" || item == "/"){
                auto left = st.top(); st.pop();
                
                // if(item == "*"){
                //     st2.top() *= left;
                // }else st2.top() = left / st2.top();



            }else{
                st2.push(item);
            }
        }




        return 0;
    }
};
int main(int argc, char const *argv[]) {
    string s = " 3+5 / 2 ";
    int ans = 5;

    IC(s, ans);

    Solution sol;

    IC(sol.calculate(s));

    return 0;
}
