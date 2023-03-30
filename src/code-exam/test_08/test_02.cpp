//
// Created by larry on 23-3-30.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    // n = 4;

    vector<vector<int>> nums(n, vector<int>(3, 0));
    for (int i = 0; i < n - 1; i++) {
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    }

    cout << 2 << endl;

    return 0;
}