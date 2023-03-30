//
// Created by larry on 23-3-30.
//

#include <iostream>
#include <vector>
#include <icecream.hpp>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        int n;
        // n = 3;
        cin >> n;

        vector<int> nums(n);
        // for(int i = 0; i< n; i++) cin>>nums[i];

        nums = {3, 3, 2};

        IC(t, n, nums);
        int ans = 0;
        while (!std::is_sorted(nums.begin(), nums.end())) {
            int max_val = nums.front();
            for (auto &num: nums) {
                if (num < max_val) {
                    break;
                } else {
                    max_val = num;
                }
            }
            for (auto &num: nums) {
                if (num == max_val) num = 0;
            }
            ++ans;

            IC(nums);

        }

        cout << ans << endl;
    }

    return 0;
}