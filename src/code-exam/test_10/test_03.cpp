//
// Created by larry on 23-4-1.
//

#include <iostream>
#include <string>

#include <icecream.hpp>

using namespace std;

bool has_seven(int n) {
    auto ns = std::to_string(n);
    for (auto &c: ns) {
        if (c == '7') return true;
    }

    return false;
}

int main() {
    int n;
    // cin>>n;

     // n = 6;
     n = 19;

    for (int i = 1; i < n - 1; i++) {
        if (i % 7 == 0) continue;
        if (has_seven(i)) continue;

        for (int j = 1; j < n - 1; j++) {
            if (j % 7 == 0) continue;
            if (has_seven(j)) continue;


            auto left = n - i - j;
            IC(i, j, left);
            if (left < 1) break;
            if(left % 7 == 0) continue;
            if (!has_seven(left)) {
                cout << i << " " << j << " " << left << endl;
                return 0;
            }
        }


    }
    cout << "No Solution!" << endl;


    return 0;
}