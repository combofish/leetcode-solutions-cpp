#include <icecream.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, m;
int tmp_val;

void traversal(unordered_map<int, vector<int>> &ump, int q, int end_node, int cost, vector<bool> &used) {
    if (q == end_node) {
        tmp_val = cost;
        return;
    }

    for (auto &v: ump[q]) {
        if (!used[v]) {
            used[v] = true;
            traversal(ump, v, end_node, cost + 1, used);
            used[v] = false;
        }
    }
}

int process(int q, unordered_map<int, vector<int>> &ump, vector<bool> &used) {
    int distance = 0;

    for (int i = 1; i <= n; ++i) {
        if (i == q) continue;
        if (used[i]) continue;

        tmp_val = 0;
        traversal(ump, q, i, 0, used);

        distance += tmp_val;
    }

    return distance;
}

int main() {

    n = 3, m = 3;

    vector<int> nums = {1, 1};
    vector<int> queries = {1, 2, 3};
    unordered_map<int, vector<int>> ump;

    for (int i = 0; i < nums.size(); ++i) {
        ump[nums[i]].emplace_back(i + 2);
        ump[i + 2].emplace_back(nums[i]);
    }

    IC(ump);


    for (auto &q: queries) {

        vector<bool> used(n + 1, 0);

        used[q] = true;
        auto ans = process(q, ump, used);
        cout << ans << " ";
    }

    cout << endl;


    return 0;
}