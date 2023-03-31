//
// Created by larry on 23-3-31.
//

#include <iostream>

using namespace std;

int main() {

    string s;
    // cin>>s;

    s = "NiuNiu won the prize!";
    const string query_s = "NiuNiu";

    int n = s.size();
    int qs = query_s.size();
    if (n < qs) return -1;

//    cout << s.size() << endl;
    for (int i = 0; i < n - qs; i++) {
//        cout << i << endl;
        auto tmp = s.substr(i, i + qs);
        if (tmp == query_s) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;


    return 0;
}