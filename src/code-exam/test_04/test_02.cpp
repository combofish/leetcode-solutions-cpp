//
// Created by larry on 23-3-26.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

//bool is_sorted(const vector<int> &nums, int n) {
//    for (int i = 1; i < n; i++) {
//        if (nums[i - 1] > nums[i]) return false;
//    }
//    return true;
//}
//
//int get_max_idx(const vector<int> nums, int rk){
//    int max_id = 0;
//    int max_num = nums.front();
//
//    for(int i = 0; i< )
//}
//
//void sort_k_nums(vector<int> &nums, int rk, int k) {
//
//    while(k--){
//        auto max_idx =
//
//
//    }
//
//}
//
//bool is_same_vec(const vector<int> &vec_a, const list<int> &list_b, int rk) {
//
//    int i = 0;
//    for (auto &n: list_b) {
//        if (i >= rk) break;
//        if (n != vec_a[i]) return false;
//        i++;
//    }
//
//    return true;
//}

#include <icecream.hpp>

bool is_same_vec(const vector<int> &vec_a, const vector<int> &vec_b, int rk) {
    for (int i = 0; i < rk; i++) {
        if (vec_a[i] != vec_b[i]) return false;
    }
    return true;
}

int main() {

    int n = 5;
    int k = 2;
    int ans = 0;

    vector<int> nums = {1, 3, 5, 4, 2};

    vector<int> sorted_nums = nums;
    std::sort(sorted_nums.begin(), sorted_nums.end());

//    list<int> l_nums(nums.begin(), nums.end());

    int rk = n;
    while (!is_same_vec(sorted_nums, nums, rk)) {
        auto need_to_del = k;
        while (need_to_del--) {
            --rk;
            nums.erase(nums.begin() + rk);
        }

        ++ans;
        IC(nums, sorted_nums);
    }


    cout << k << endl;


//    int rk = n;
//    while (!is_sorted(nums, rk)) {
//        sort_k_nums(nums, rk, k);
//        rk -= k;
//        ++ans;
//    }

    cout << ans << endl;


    return 0;
}

/**


*/