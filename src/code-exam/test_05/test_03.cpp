//
// Created by larry on 23-3-26.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

int kl(const vector<double> &nums, int k, double t) {
    double ans = 0;

    auto sum_num = std::accumulate(nums.begin(), nums.end(), 0.0);

//    auto nv_sum = 0.0;
//    for (auto num: nums) nv_sum += (1 / num);

    ans = 0.5 * (::log10(std::abs(sum_num) / k) + sum_num - k);

    return ans > t ? 1 : 0;
}

int main() {


    int T;
    T = 1;

    while (T--) {
        int k;
        double t;

        k = 3;


        vector<double> nums(k, 0);

//        nums = {4.5, 3.4, 6.5};
        // t = 10.5;

        nums = {4.5, 3.4, 6.5};
        t = 2.2;

        cout << kl(nums, k, t) << endl;

    }
    return 0;
}