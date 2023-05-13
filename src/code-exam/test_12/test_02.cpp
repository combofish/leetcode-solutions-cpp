//
// Created by larry on 23-5-6.
//

#include <iostream>
#include <string>
#include <vector>
//#include <icecream.hpp>
#include <unordered_map>
#include <algorithm>

using namespace std;
const int vals[3][3] = {
        {0,  13, 4},
        {13, 7,  20},
        {4,  20, 5}
};

unordered_map<char, int> ump = {
        {'!', 0},
        {'@', 1},
        {'#', 2}
};

string add_two_string(string &s1, string &s2) {
    int over = 0;
    string ans;
    while (!s1.empty() || !s2.empty()) {
        auto f_back = !s1.empty() ? s1.back() : '0';
        s1.pop_back();
        auto s_back = !s2.empty() ? s2.back() : '0';
        s2.pop_back();


        if (f_back == '.') {
            ans.push_back('.');
            continue;
        } else if (f_back == '!' || f_back == '#' || f_back == '@') {
            auto a = ump[f_back];
            auto b = ump[s_back];
            auto tmp_sum = vals[a][b] + over;

            over = tmp_sum / 10;
            ans.push_back((tmp_sum % 10) + '0');
        } else {
            auto a = f_back - '0';
            auto b = s_back - '0';
            auto tmp_sum = a + b + over;

            over = tmp_sum / 10;
            ans.push_back((tmp_sum % 10) + '0');
        }
//        IC(f_back, s_back, ans);
    }
//    std::reverse(ans.begin(), ans.end());
//    IC(ans);

    if (over != 0) {
        ans.push_back(over + '0');
    }

    return ans;
}

string add_dec_string(string &s1, string &s2) {
    // dec int;
    // int over = 0;
    string ans;

    while (s1.back() != '.') {
        ans.push_back(s1.back());
        s1.pop_back();
    }
    ans.push_back(s1.back());
    s1.pop_back();

    auto tmp = add_two_string(s1, s2);
    ans.append(tmp);
//    IC(ans);

    return ans;

}

int main() {
    int N;
    // cin>>N;
    N = 15;

    string expr;
    // expr = "123.45#1+126.53@";
    // expr = "123+456";
    // expr = "123.4+456";
    // expr = "123+456.7";
    expr = "1#3+1#0.4";

    // vector<string> exps;
    pair<string, string> exps;
    pair<int, int> types = {-1, -1};
    int first_len = 0;
    int second_len = 0;
    for (int i = 0; i < expr.size(); ++i) {
        if (expr[i] == '.') {
            if (exps.first.empty())
                types.first = i;
            else
                types.second = i;
        }
        if (expr[i] == '+') {
            first_len = i;
            second_len = N - i;
            exps.first = expr.substr(0, i);
            exps.second = expr.substr(i + 1);
        }
    }
//    IC(exps, types);
//    IC(vals, ump);
//    IC(first_len, second_len);
//    IC(expr.size(), N);


    string ans;
    if (types.first != -1 && types.second != -1) {
        // both dec
        int first_sub = first_len - types.first - 1;
        int second_sub = expr.size() - types.second - 1;

//        IC(first_sub, second_sub);
        int diff = first_sub - second_sub;
        if (diff > 0) {
            while (diff--) {
                exps.second.push_back('0');
            }
        } else if (diff < 0) {
            diff = -diff;
            while (diff--) {
                exps.first.push_back('0');
            }
        }

        ans = add_two_string(exps.first, exps.second);

    } else if (types.first == -1 && types.second == -1) {
        ans = add_two_string(exps.first, exps.second);
    } else {
        //
        if (types.first == -1) ans = add_dec_string(exps.second, exps.first);
        else ans = add_dec_string(exps.first, exps.second);
    }


    std::reverse(ans.begin(), ans.end());
//    while(ans.back() == '0'){
//        ans.pop_back();
//    }

    bool isDec = false;
    for (auto &c: ans) {
        if (c == '.') {
            isDec = true;
            break;
        }
    }
    if (isDec) {
        while (ans.back() == '0') {
            ans.pop_back();
        }
        if (ans.back() == '.')
            ans.pop_back();
    }

    int lk = 0;
    while (ans[lk] == '0') {
        ++lk;
    }
    ans = ans.substr(lk);

//    IC(ans);

    cout << ans << endl;


    return 0;
}