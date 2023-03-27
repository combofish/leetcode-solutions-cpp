//
// Created by larry on 23-3-26.
//

#include <iostream>
#include <string>
// #include<unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;


int main() {

    int n;

    n = 3;
    vector<string> nn(3, "");
    vector<string> right(3, "");

    nn = {"ABC", "AB", "CD"};
    right = {"ABC", "ABD", "BC"};

    int ans = 0;
    for (int i = 0; i < n; i++) {

        unordered_map<char, int> ump;
        for (auto &c: right[i]) ump[c]++;
        for (auto &c: nn[i]) ump[c]--;

        bool has_down = false;
        bool has_up = false;

        for (auto &item: ump) {
            if (item.second == -1) {
                has_down = true;
            } else if (item.second == 1) {
                has_up = true;
            }
        }

        if (!has_down && !has_up) ans += 3;
        else if (has_down) ans += 0;
        else if (has_up) ans += 1;

    }

    cout << ans << endl;


    return 0;
}