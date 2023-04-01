//
// Created by larry on 23-4-1.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> ump;
    for (const auto &c: s)
        ++ump[c];

    cout << ump['a'] << " " << ump['b'] << " " << ump['c'] << endl;


    return 0;
}