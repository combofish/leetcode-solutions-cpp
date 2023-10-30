#include <bits/stdc++.h>
#include <icecream.hpp>
using namespace std;

int sol(const vector<int> &nums) {
    int ans = 1;
    int cur_sum = 0;
    int n = nums.size();

    unordered_map<int, int> ump;
    ump[0] = -1;

    for (int i = 0; i < n; ++i) {
        int tmp = cur_sum;
        tmp += (nums[i] == 1) ? 1 : -1;

        if (ump.count(tmp)) {
            ans = std::max(ans, i - ump[tmp]);
        } else {
            ump[tmp] = i;
        }

        IC(tmp, cur_sum, ans);
        IC(ump);
        cur_sum = tmp;
        cout << endl;
    }

    return ans;
}

int main(int argc, char const *argv[]) {

    vector<int> nums = {1, 1, 1, 1, 1, 2, 2, 2, 1};
    int ans = 4;

    IC(nums, ans);

    IC(sol(nums));
    return 0;
}
