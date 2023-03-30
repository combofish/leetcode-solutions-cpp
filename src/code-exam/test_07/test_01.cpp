//
// Created by larry on 23-3-29.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    // cin>>s;

    s = "1234567890";

    int ans = 0;
    for (const auto &c: s) {
        if (c == '0' || c == '6' || c == '9') ans++;
        else if (c == '8') ans += 2;
    }


    cout << ans << endl;

    return 0;
}