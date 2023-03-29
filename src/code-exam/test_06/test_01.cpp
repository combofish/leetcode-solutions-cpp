#include <iostream>
#include <vector>
#include <algorithm>

#include <icecream.hpp>
using namespace std;


int main() {

    int n;
    long long m, k;

    // cin>>n>>m>>k;
    n = 4;
    m = 4;
    k = 2;

    vector<int> nums(n);

    nums = {4, 3, 2, 1};

    std::sort(nums.begin(), nums.end());

    IC(nums);

    int max_cnt = 0;
    long long dmg = 0;
    for (int i = 0; i < m; i++) {
        if (max_cnt < k) {
            dmg += nums.back();
            ++max_cnt;
        } else {
            max_cnt = 0;
            dmg += nums[n - 2];
        }
    }

    cout<<dmg<<endl;

    return 0;
}
