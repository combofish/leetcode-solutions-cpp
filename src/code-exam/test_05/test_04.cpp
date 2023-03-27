//
// Created by larry on 23-3-26.
//
#include <iostream>
#include <vector>
#include <unordered_set>

#include <icecream.hpp>

using namespace std;

int is_may_up(const vector<int> &nums, int lk, const int k) {
    unordered_set<int> uet;

    int min_val = nums[lk];
    for (int i = lk; i < nums.size(); i++) {
        if (uet.count(nums[i])) {
            break;
        }
        if (nums[i] < min_val) min_val = nums[i];
        uet.insert(nums[i]);
    }

    int n = uet.size();
    if (n < k) return 0;

    for (int i = 0; i < n; i++) {
        if (!uet.count(min_val + i)) {
            return 0;
        }
    }


    IC(uet, uet.size());
    return 1;

    // return 1 or 0
}

int can_be(const unordered_set<int> &uet, int lk, const int k) {
    if (uet.size() != k) return 0;
    for (int i = 0; i < k; i++) {
        if (!uet.count(lk + i)) return 0;
    }
    return 1;
}

int main() {

    int n, k;

    // cin>>n>>k;
    n = 4;
    k = 2;

    vector<int> nums(n, 0);

    // for(int i = 0; i< n; i++) cin>>nums[i];
    nums = {2, 3, 3, 2};

    int lk = 0;
    int ans = 0;

    unordered_set<int> uet;
//    int lk = 0;
//
//    int min_val = nums[lk];
//    for (int i = lk; i < k; i++) {
//        if (uet.count(nums[i])) break;
//        min_val = std::min(nums[i], min_val);
//        uet.insert(nums[i]);
//    }
//
//    if (uet.size() == k) {
//        ans += can_be(uet, lk, k);
//    }
//
////
////        for (int i = lk + uet.size(); i < n; i++) {
////
////
////        }
//
//    int rk = lk + uet.size();
//
//    while(lk < n){
//        uet.erase(nums[lk++]);
//
//    }


    for (int i = 0; i < n; i++) {
        int tmp_res = 0;
//
//
//        int min_val = nums[lk];
//        for (int i = lk; i < nums.size(); i++) {
//            if (uet.count(nums[i])) {
//                break;
//            }
//            if (nums[i] < min_val) min_val = nums[i];
//            uet.insert(nums[i]);
//        }
////
//        int n = uet.size();
//        if (n < k) return 0;


        ans += tmp_res;
    }

    cout << ans << endl;

    IC(ans, k);
    return 0;
}