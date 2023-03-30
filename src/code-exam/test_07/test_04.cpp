//
// Created by larry on 23-3-29.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <icecream.hpp>

using namespace std;

int ans = 0;


void backtracking(const vector<vector<int>> &nums,
                  unordered_map<int, vector<int>> &ump,
                  vector<bool> &used,
                  int n, // b =  dot number
                  int idx,
                  int cur) {

    ans = std::max(ans, cur);
//    if (idx >= n - 1) {
//        return;
//    }

    unordered_map<int, vector<int>> related;

    for (int j = 0; j < n - 1; j++) {
        if (used[j]) {
            auto ldot = nums[j][0];
            auto rdot = nums[j][1];
            for (auto &item: ump[ldot]) {
                related[item].emplace_back(ldot);
                related[ldot].emplace_back(item);
            }
            for (auto &item: ump[rdot]) {
                related[item].emplace_back(rdot);
                related[rdot].emplace_back(item);
            }

            related[rdot].emplace_back(ldot);
            related[ldot].emplace_back(rdot);
        }
    }

    IC(cur, related);

    for (int i = idx; i < n - 1; i++) {
        if (used[i]) continue;

        // does not use.
        auto cur_ldot = nums[i][0];
        auto cur_rdot = nums[i][1];

        bool canuse = true;
        for (auto &item: related[cur_ldot]) {
            if (item == cur_rdot) canuse = false;
        }

        if (!canuse) continue;


        // can be use
        used[i] = true;
        backtracking(nums, ump, used, n, i + 1, cur + nums[i].back());
        used[i] = false;

    }

}

int main() {
    int n;

    // cin>>n;

    n = 5;

    vector<vector<int>> nums(n - 1, vector<int>(3, 0));

//    for (int i = 1; i < n; i++) {
//        for (int j = 0; j < 3; j++) {
//            cin >> nums[i][j];
//        }
//    }

    nums = {{1, 2, 2},
            {2, 3, 5},
            {3, 4, 4},
            {3, 5, 3}};

    unordered_map<int, vector<int>> ump;
//    unordered_map<int, bool> dot;

    for (const auto &item: nums) {
        ump[item[0]].emplace_back(item[1]);
        ump[item[1]].emplace_back(item[0]);

//        // dot u
//        dot[item[0]] = false;
//        dot[item[1]] = false;
    }

    IC(ump);
    vector<bool> used(n - 1, false);

    for (int i = 0; i < n - 1; i++) {
        used[i] = true;
        backtracking(nums, ump, used, n, i + 1, nums[i].back());
        used[i] = false;
    }


    cout << ans << endl;

    return 0;
}

/**
*
 *
    vector<int> dots;
    for(auto &item: dot){
        dots.emplace_back(item.first);
    }

    for(int i = 0; i< n; i++){
        dot[dots[i]] = true;

        backtracking();
        dot[dots[i]] = false;
    }





             for (auto &item: ump[ldot]) {
                for (int k = 0; k < n; k++) {
                    if (nums[k][0] == item && nums[k][1] == ldot) {
                        used[k] = true;
                    } else if (nums[k][0] == ldot && nums[k][1] == item) {
                        used[k] = true;
                    }
                }
            }

            for (auto &item: ump[rdot]) {
                for (int k = 0; k < n; k++) {
                    if (nums[k][0] == item && nums[k][1] == ldot) {
                        used[k] = true;
                    } else if (nums[k][0] == ldot && nums[k][1] == item) {
                        used[k] = true;
                    }
                }
            }
*/