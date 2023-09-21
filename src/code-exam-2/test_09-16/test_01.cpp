#include <icecream.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
private:
    int backtracking(int idx, vector<int> &salary, unordered_map<int, vector<int>> &ump,
                     vector<int> &used) {

        IC(idx, used);

        if (used[idx] != -1) return used[idx];

        // bool can_use = true;
        int curr_val = salary[idx];
        for (auto &item: ump[idx]) {

            if (used[item - 1] == -1) {
                curr_val += backtracking(item - 1, salary, ump, used);
            } else {
                curr_val += used[item - 1];
            }
        }

        used[idx] = curr_val;
        return curr_val;
    }

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param salary int整型vector
     * @param subordinate int整型vector<vector<>>
     * @param id int整型
     * @return int整型
     */
    int getTotalSalary(vector<int> &salary, vector<vector<int>> &subordinate, int id) {
        // write code here

        int n = (int) salary.size();
        vector<int> used(n, -1);
        unordered_map<int, vector<int>> ump;

        for (int i = 0; i < n; ++i) {
            if (subordinate[i].empty()) {
                used[i] = salary[i];
            } else {
                ump[i] = subordinate[i];
            }
        }

        IC(used, ump);

        return backtracking(id - 1, salary, ump, used);
    }
};

int main() {

//    vector<int> nums = {5000, 1000, 2000};
//    vector<vector<int>> recs = {{2, 3}, {}, {}};

    vector<int> nums = {5000, 3000, 2000};
    vector<vector<int>> recs = {{2}, {3}, {}};
    int idx = 1;

    Solution sol;

    IC(sol.getTotalSalary(nums, recs, idx));


    return 0;
}