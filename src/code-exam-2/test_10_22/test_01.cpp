#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <icecream.hpp>

using namespace std;

void out_st(stack<char> st){
    string ans;
    while(!st.empty()){
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
    //cin>>str;

    str = "2(a3(b))2(cd)e2(f)";

    int n = str.size();
    vector<char> st;

    for(auto &c: str){
        IC(c);

        if(c == ')'){
            string tmp;
            while(!st.empty() && st.back() != '('){
                tmp += st.back();
                st.pop_back();
            }
            st.pop_back(); // pop '('

            // C(st);
            // out_st(st);
            IC(st);

            string cnt_string;
            while(!st.empty() && std::isdigit(st.back())){
                cnt_string += st.back();
                st.pop_back();
            }

            std::reverse(cnt_string.begin(),cnt_string.end());
            int cnt = std::stoi(cnt_string);

            // IC(cnt, tmp);

            for(int i = 0; i< cnt; ++i){
                for(auto &per_c: tmp){
                    st.emplace_back(per_c);
                }
            }



        }else{
            st.emplace_back(c);
        }
    }

    // string ans;
    // while(!st.empty()){
    //     ans += st.top();
    //     st.pop();
    // }

    // cout<<st<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")