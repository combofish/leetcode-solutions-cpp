#include <bits/stdc++.h>
// #include <icecream.hpp>

using namespace std;


int main(int argc, char const *argv[]) {
    int n = 6, k = 3;
    // cin >> n >> k;

    // vector<int> nums(n);
    // for (int i = 0; i < n; ++i) {
    //     cin >> nums[i];
    // }

    vector<int> nums = {13, 5, 1, 8, 21, 2};

    std::sort(nums.begin(), nums.end());

    if (k == 2) {
        cout << nums.back() - nums.front() << endl;
        return 0;
    }

    // k > 2;

    vector<int> ans = {0, n - 1};
    int diff = nums.back() - nums.front();

    while (ans.size() < k) {
        int min_val = diff;

        // for (int i = 1; i < ans.back(); ++i) {
        //     auto middle_pair = find_between(nums, ans[i - 1], ans[i]);

        //     if (middle_pair.first == -1) continue;
        //     else {
        //         min_val = std::min({min_val, middle_pair.first - nums[ans[i - 1]], nums[ans[i]] - middle_pair.first});
        //     }
        // }
    }


    return 0;
}
