#include <iostream>

using namespace std;

inline int getMaxSub(const vector<int> &nums){
    int n = nums.size();
    int ans = nums.front();

    int cur_sum = nums.front();

    for(int i = 1; i< n; ++i){
        cur_sum = std::max(cur_sum + nums[i], nums[i]);
        ans = std::max(ans, cur_sum);
    }
    return ans;
}

int main() {

    int t;
    // cin>> t;
    t = 1;

    while (t-- > 0) {
        int n, x;

        // cin>>n>>x;
        n = 5;
        x = 10;

        vector<int> nums(n);
        //        for(int i = 0; i< n; ++i){
        //            cin>>nums[i];
        //        }

        nums = {5, -1, -5, -3, 2};

        int ans = 0;

        for(int i = 0; i< n; ++i){
            auto tmp = nums[i];
            nums[i] = x;
            ans = std::max(ans, getMaxSub(nums));
            nums[i] = tmp;
        }

        // cout<<x<<endl;
        cout << ans << endl;
    }

    return 0;
}