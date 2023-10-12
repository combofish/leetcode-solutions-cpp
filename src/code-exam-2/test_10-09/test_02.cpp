#include <bits/stdc++.h>
#include <iostream>
#include <string>


using namespace std;

int main() {

    string s = "acdk", t = "ckad";

    int sz = t.size();

    int rk = 0;
    for (auto c: s) {
        if (c == t[rk]) {
            ++rk;
        }
    }

    if (rk == 0) cout << -1 << endl;
    else
        cout << sz - rk << endl;

    return 0;
}