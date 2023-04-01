//
// Created by larry on 23-4-1.
//

#include <iostream>
#include <vector>

#include <icecream.hpp>

using namespace std;

const int mod = 100000007;

int main() {

    int n;
    // cin>>n;

    n = 5;

    vector<int> nums(n, 0);

    nums = {3, 5, 2, 4, 1};

    for (auto &num: nums) {
        long long tmp = (long long) num * num;
        num = tmp;
    }
    IC(nums);

    int ans = 0;
    for (int x = 0; x < n - 2; x++) {
        for (int y = x + 1; y < n - 1; y++) {
            for (int z = y + 1; z < n; z++) {

                if (nums[x] < nums[z] && nums[z] < nums[y]) {
                    ++ans;
                    ans %= mod;
                }

            }
        }

    }

    cout << ans << endl;

    return 0;
}