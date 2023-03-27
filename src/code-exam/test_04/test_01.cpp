//
// Created by larry on 23-3-26.
//

#include <iostream>
#include <string>

using namespace std;


inline char dSuc(char c, int n) {
    int idx = c - 'a';

    if (idx - n >= 0) idx -= n;
    else {
        n -= idx;
        idx = 26 - n;
    }

    return 'a' + idx;

}

int main() {

    int n = 4;
    string s = "def";

    n %= 26;

    for (auto &c: s) {
        c = dSuc(c,n);
    }

    cout<<s<<endl;


    return 0;
}

/**


*/