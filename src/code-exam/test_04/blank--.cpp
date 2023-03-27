#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

bool is_same_vec(const vector<int> &vec_a, const vector<int> &vec_b, int rk) {
    for (int i = 0; i < rk; i++) {
        if (vec_a[i] != vec_b[i]) return false;
    }
    return true;
}

int main() {

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        int ans = 0;

        cin >> n >> k;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }


        vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());


        int rk = n;
        while (!is_same_vec(sorted_nums, nums, rk)) {
            auto need_to_del = k;
            while (need_to_del--) {
                --rk;
                nums.erase(nums.begin() + rk);
            }

            ++ans;

        }
        cout << ans << endl;


    }


    return 0;
}