#include <bits/stdc++.h>
#include <icecream.hpp>
#include <iostream>
using namespace std;

int ans;

void dfs(const string &s, int idx, int cnt) {
    IC(idx, cnt);


    if (idx >= s.size()) {
        ans = std::max(ans, cnt);
        return;
    }


    if (s[idx] == '0') {
        dfs(s, idx + 1, cnt + 1);
        return;
    }


    int sum = 0;
    int INF = 999;

    for (int i = idx; i < s.size(); ++i) {
        sum = sum * 10 + (s[i] - '0');

        IC(sum);

        if (sum > INF) break;

        if(sum %3 == 0) dfs(s, i + 1, cnt + 1);
        else dfs(s, i+1, cnt);
    }
}


int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }

    string line;
    // cin>>line;

    line = "1123";
    IC(line);

    ans = 0;

    dfs(line, 0, 0);

    cout << ans << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")